/************************************************************************
**
**  Copyright (C) 2018  spdevapp <spdevapp@joara.com>
**
**  This file is part of Aries.
**
**  Aries is video player for ffmepg.
**
*************************************************************************/

#include <QtCore/QStandardPaths>

#include "SettingData.h"



SettingData::SettingData()
	: QSettings(QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/aries/aries.ini", QSettings::IniFormat)
{
}


SettingData::~SettingData()
{
}
