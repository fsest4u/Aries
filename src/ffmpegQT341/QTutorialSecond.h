/************************************************************************
**
**  Copyright (C) 2018  fsest4u <fsest4u@gmail.com>
**
**  This file is part of Aries.
**
**  Aries is video player for ffmepg.
**
*************************************************************************/

#ifndef __QTUTORIAL_SECOND_H
#define __QTUTORIAL_SECOND_H


#include <QIODevice>
#include <QFile>
#include <QImage>

//#include "ffmpeg.h"

class QTutorialSecond
{
   protected:



   public:
      // Public interface
      QTutorialSecond();
      virtual ~QTutorialSecond();

	  bool OpenFile(QString filename);

};

#endif // __QTUTORIAL_SECOND_H
