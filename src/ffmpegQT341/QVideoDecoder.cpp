/*
	QTFFmpegWrapper - QT FFmpeg Wrapper Class 
	Copyright (C) 2009,2010:
			Daniel Roggen, droggen@gmail.com			
			
	All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FREEBSD PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "QVideoDecoder.h"
#include <limits.h>
#include <stdint.h>
#include "ffmpeg.h"


/******************************************************************************
*******************************************************************************
* QVideoDecoder   QVideoDecoder   QVideoDecoder   QVideoDecoder   QVideoDecoder
*******************************************************************************
******************************************************************************/

/******************************************************************************
* PUBLIC   PUBLIC   PUBLIC   PUBLIC   PUBLIC   PUBLIC   PUBLIC   PUBLIC   PUBLIC
******************************************************************************/


/**
   \brief Constructor - opens a video on later openFile call
**/
QVideoDecoder::QVideoDecoder()
{

}
/**
   \brief Constructor - opens directly a video
**/
QVideoDecoder::QVideoDecoder(QString file)
{

	openFile(file.toStdString().c_str());
}

QVideoDecoder::~QVideoDecoder()
{
   close();
}



void QVideoDecoder::close()
{

}



bool QVideoDecoder::openFile(QString filename)
{
   // Close last video..
   close();

   AVFormatContext *fmt_ctx = NULL;
   AVDictionaryEntry *tag = NULL;
   int ret;



   av_register_all();
   if ((ret = avformat_open_input(&fmt_ctx, filename.toStdString().c_str(), NULL, NULL)))
	   return ret;

   while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX))) {
	   //printf("%s=%s\n", tag->key, tag->value);
	   qDebug("%s=%s\n", tag->key, tag->value);
   }

   avformat_close_input(&fmt_ctx);

   return true;
}
