/************************************************************************
**
**  Copyright (C) 2018  fsest4u <fsest4u@gmail.com>
**
**  This file is part of Aries.
**
**  Aries is video player for ffmepg.
**
*************************************************************************/

#ifndef __QTUTORIAL_FIRST_H
#define __QTUTORIAL_FIRST_H


#include <QIODevice>
#include <QFile>
#include <QImage>

#include "ffmpeg.h"

class QTutorialFirst
{
   protected:



   public:
      // Public interface
      QTutorialFirst();
      virtual ~QTutorialFirst();

	  bool OpenFile(QString filename);
	  void SaveFrame(AVFrame *pFrame, int width, int height, int iFrame);



};

#endif // __QTUTORIAL_FIRST_H
