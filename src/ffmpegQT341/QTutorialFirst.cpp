/************************************************************************
**
**  Copyright (C) 2018  fsest4u <fsest4u@gmail.com>
**
**  This file is part of Aries.
**
**  Aries is video player for ffmepg.
**
*************************************************************************/

#include "QTutorialFirst.h"
#include <limits.h>
#include <stdint.h>
//#include "ffmpeg.h"


/**
   \brief Constructor - opens a video on later openFile call
**/
QTutorialFirst::QTutorialFirst()
{

}


QTutorialFirst::~QTutorialFirst()
{

}

bool QTutorialFirst::OpenFile(QString filename)
{
	// Initalizing these to NULL prevents segfaults!
	AVFormatContext   *pFormatCtx = NULL;
	int               i, videoStream;
	AVCodecContext    *pCodecCtxOrig = NULL;
	AVCodecContext    *pCodecCtx = NULL;
	AVCodec           *pCodec = NULL;
	AVFrame           *pFrame = NULL;
	AVFrame           *pFrameRGB = NULL;
	AVPacket          packet;
	int               frameFinished;
	int               numBytes;
	uint8_t           *buffer = NULL;
	struct SwsContext *sws_ctx = NULL;

	if (filename.isEmpty()) {
		qDebug("Please provide a movie file\n");
		return false;
	}
	// Register all formats and codecs
	av_register_all();

	// Open video file
	if (avformat_open_input(&pFormatCtx, filename.toStdString().c_str(), NULL, NULL) != 0)
		return false; // Couldn't open file

				   // Retrieve stream information
	if (avformat_find_stream_info(pFormatCtx, NULL)<0)
		return false; // Couldn't find stream information

				   // Dump information about file onto standard error
	av_dump_format(pFormatCtx, 0, filename.toStdString().c_str(), 0);

	// Find the first video stream
	videoStream = false;
	for (i = 0; i<pFormatCtx->nb_streams; i++)
		if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
			videoStream = i;
			break;
		}
	if (videoStream == -1)
		return false; // Didn't find a video stream

				   // Get a pointer to the codec context for the video stream
	pCodecCtxOrig = pFormatCtx->streams[videoStream]->codec;
	// Find the decoder for the video stream
	pCodec = avcodec_find_decoder(pCodecCtxOrig->codec_id);
	if (pCodec == NULL) {
		fprintf(stderr, "Unsupported codec!\n");
		return false; // Codec not found
	}
	// Copy context
	pCodecCtx = avcodec_alloc_context3(pCodec);
	if (avcodec_copy_context(pCodecCtx, pCodecCtxOrig) != 0) {
		fprintf(stderr, "Couldn't copy codec context");
		return false; // Error copying codec context
	}

	// Open codec
	if (avcodec_open2(pCodecCtx, pCodec, NULL)<0)
		return false; // Could not open codec

				   // Allocate video frame
	pFrame = av_frame_alloc();

	// Allocate an AVFrame structure
	pFrameRGB = av_frame_alloc();
	if (pFrameRGB == NULL)
		return false;

	// Determine required buffer size and allocate buffer
	numBytes = avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width,
		pCodecCtx->height);
	buffer = (uint8_t *)av_malloc(numBytes * sizeof(uint8_t));

	// Assign appropriate parts of buffer to image planes in pFrameRGB
	// Note that pFrameRGB is an AVFrame, but AVFrame is a superset
	// of AVPicture
	avpicture_fill((AVPicture *)pFrameRGB, buffer, AV_PIX_FMT_RGB24,
		pCodecCtx->width, pCodecCtx->height);

	// initialize SWS context for software scaling
	sws_ctx = sws_getContext(pCodecCtx->width,
		pCodecCtx->height,
		pCodecCtx->pix_fmt,
		pCodecCtx->width,
		pCodecCtx->height,
		AV_PIX_FMT_RGB24,
		SWS_BILINEAR,
		NULL,
		NULL,
		NULL
	);

	// Read frames and save first five frames to disk
	i = 0;
	while (av_read_frame(pFormatCtx, &packet) >= 0) {
		// Is this a packet from the video stream?
		if (packet.stream_index == videoStream) {
			// Decode video frame
			avcodec_decode_video2(pCodecCtx, pFrame, &frameFinished, &packet);

			// Did we get a video frame?
			if (frameFinished) {
				// Convert the image from its native format to RGB
				sws_scale(sws_ctx, (uint8_t const * const *)pFrame->data,
					pFrame->linesize, 0, pCodecCtx->height,
					pFrameRGB->data, pFrameRGB->linesize);

				// Save the frame to disk
				if (++i <= 5)
					SaveFrame(pFrameRGB, pCodecCtx->width, pCodecCtx->height,
						i);
			}
		}

		// Free the packet that was allocated by av_read_frame
		av_free_packet(&packet);
	}

	// Free the RGB image
	av_free(buffer);
	av_frame_free(&pFrameRGB);

	// Free the YUV frame
	av_frame_free(&pFrame);

	// Close the codecs
	avcodec_close(pCodecCtx);
	avcodec_close(pCodecCtxOrig);

	// Close the video file
	avformat_close_input(&pFormatCtx);

}

void QTutorialFirst::SaveFrame(AVFrame *pFrame, int width, int height, int iFrame) {
	FILE *pFile;
	char szFilename[32];
	int  y;

	// Open file
	sprintf(szFilename, "frame%d.ppm", iFrame);
	pFile = fopen(szFilename, "wb");
	if (pFile == NULL)
		return;

	// Write header
	fprintf(pFile, "P6\n%d %d\n255\n", width, height);

	// Write pixel data
	for (y = 0; y<height; y++)
		fwrite(pFrame->data[0] + y*pFrame->linesize[0], 1, width * 3, pFile);

	// Close file
	fclose(pFile);
}


