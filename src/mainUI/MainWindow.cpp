/************************************************************************
**
**  Copyright (C) 2018  spdevapp <spdevapp@joara.com>
**
**  This file is part of Aries.
**
**  Aries is video player for ffmepg.
**
*************************************************************************/

#include <QtCore/QtDebug>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "misc/SettingData.h"

static const QString SETTINGS_GROUP = "mainWindow";

const QStringList AUDIO_EXTENSIONS = QStringList() << "aac" << "m4a" << "mp3" << "mpeg" << "mpg" << "oga" << "ogg";
const QStringList VIDEO_EXTENSIONS = QStringList() << "m4v" << "mp4" << "mov" << "ogv" << "webm" << "vtt" << "ttml";

const QString AUDIO_EXTENSION = "Audio Files (*.aac *.m4a *.mp3 *.mpeg *.mpg *.oga *.ogg)";
const QString VIDEO_EXTENSION = "Video Files (*.m4v *.mp4 *.mov *.ogv *.webm *.vtt *.ttml)";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, m_LastFolderOpen("")
{
    ui->setupUi(this);

	ReadSetting();
	InitUI();
	ConnectSignalsToSlots();
}

MainWindow::~MainWindow()
{

	WriteSetting();
	
	delete ui;
}

void MainWindow::ReadSetting()
{
	SettingData settings;
	settings.beginGroup(SETTINGS_GROUP);
	// The size of the window and it's full screen status
	QByteArray geometry = settings.value("geometry").toByteArray();

	if (!geometry.isNull()) {
		restoreGeometry(geometry);
	}

	// Last folder open
	m_LastFolderOpen = settings.value("lastfolderopen").toString();

	settings.endGroup();

}

void MainWindow::WriteSetting()
{
	SettingData settings;
	settings.beginGroup(SETTINGS_GROUP);
	// The size of the window and it's full screen status
	settings.setValue("geometry", saveGeometry());

	settings.setValue("lastfolderopen", m_LastFolderOpen);

	settings.endGroup();

}

void MainWindow::InitUI()
{

}

void MainWindow::ConnectSignalsToSlots()
{

}

void MainWindow::on_actionOpen_triggered()
{
	qDebug() << "on_actionOpen_triggered()";
	// select directory
	if (!QFileInfo(m_LastFolderOpen).exists()) {
		m_LastFolderOpen = QDir::homePath();
	}

	QString default_filter = "*";
	QString filename = QFileDialog::getOpenFileName(this, tr("Open Video File"), m_LastFolderOpen, VIDEO_EXTENSION);
	if (filename.isEmpty()) {
		QMessageBox::warning(this, tr("Open Video File"), tr("Please select a video file to open."));
		return;
	}

	if (!filename.isEmpty())
		m_LastFolderOpen = QFileInfo(filename).absolutePath();

}

void MainWindow::on_actionExit_triggered()
{
	qDebug() << "on_actionExit_triggered()";
	QMessageBox::StandardButton btn;
	btn = QMessageBox::question(this, tr(QCoreApplication::applicationName().toStdString().c_str()), tr("Are you sure you want to exit the application?"), QMessageBox::Ok | QMessageBox::Cancel);

	if (btn == QMessageBox::Ok) {
		this->close();
		return;
	}
}
