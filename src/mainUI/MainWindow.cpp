/************************************************************************
**
**  Copyright (C) 2018  fsest4u <fsest4u@gmail.com>
**
**  This file is part of Aries.
**
**  Aries is video player for ffmepg.
**
*************************************************************************/

#include <QtCore/QtDebug>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtGui/QPainter>

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "misc/SettingData.h"
#include "cio.h"
#include "SDL.h"

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
	//ConsoleInit();
}

void MainWindow::ConnectSignalsToSlots()
{

}

void MainWindow::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void MainWindow::image2Pixmap(QImage &img, QPixmap &pixmap)
{
	// Convert the QImage to a QPixmap for display
	pixmap = QPixmap(img.size());
	QPainter painter;
	painter.begin(&pixmap);
	painter.drawImage(0, 0, img);
	painter.end();
}

/******************************************************************************
*******************************************************************************
* Decoder demo   Decoder demo   Decoder demo   Decoder demo   Decoder demo
*******************************************************************************
******************************************************************************/

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

	if (!filename.isEmpty()) {
		m_LastFolderOpen = QFileInfo(filename).absolutePath();
		loadVideo(filename);
	}

}

/**
Prompts the user for the video to load, and display the first frame
**/
void MainWindow::loadVideo(QString fileName)
{
	m_Decoder.openFile(fileName);
	//if (m_Decoder.isOk() == false)
	//{
	//	QMessageBox::critical(this, "Error", "Error loading the video");
	//	return;
	//}

	// Get a new frame
	nextFrame();
	// Display a frame
	displayFrame();

}

void MainWindow::errLoadVideo()
{
	QMessageBox::critical(this, "Error", "Load a video first");
}
bool MainWindow::checkVideoLoadOk()
{
	//if (m_Decoder.isOk() == false)
	//{
	//	errLoadVideo();
	//	return false;
	//}
	return true;
}

/**
Decode and display a frame
**/
void MainWindow::displayFrame()
{
	//// Check we've loaded a video successfully
	//if (!checkVideoLoadOk())
	//	return;

	//QImage img;

	//// Decode a frame
	//int et, en;
	//if (!m_Decoder.getFrame(img, &en, &et))
	//{
	//	QMessageBox::critical(this, "Error", "Error decoding the frame");
	//	return;
	//}
	//// Convert the QImage to a QPixmap for display

	//QPixmap p;
	//image2Pixmap(img, p);
	//// Display the QPixmap
	//ui->labelVideoFrame->setPixmap(p);

	//// Display the video size
	//ui->labelVideoInfo->setText(QString("Size %2 ms. Display: #%3 @ %4 ms.").arg(m_Decoder.getVideoLengthMs()).arg(en).arg(et));

}

void MainWindow::nextFrame()
{
	//if (!m_Decoder.seekNextFrame())
	//{
	//	QMessageBox::critical(this, "Error", "seekNextFrame failed");
	//}
}

/**
Display next frame
**/
void MainWindow::on_pushButtonNextFrame_clicked()
{
	nextFrame();
	displayFrame();
}




void MainWindow::on_pushButtonSeekFrame_clicked()
{
	//// Check we've loaded a video successfully
	//if (!checkVideoLoadOk())
	//	return;

	//bool ok;

	//int frame = ui->lineEditFrame->text().toInt(&ok);
	//if (!ok || frame < 0)
	//{
	//	QMessageBox::critical(this, "Error", "Invalid frame number");
	//	return;
	//}

	//// Seek to the desired frame
	//if (!m_Decoder.seekFrame(frame))
	//{
	//	QMessageBox::critical(this, "Error", "Seek failed");
	//	return;
	//}
	//// Display the frame
	//displayFrame();

}


void MainWindow::on_pushButtonSeekMillisecond_clicked()
{
	//// Check we've loaded a video successfully
	//if (!checkVideoLoadOk())
	//	return;

	//bool ok;

	//int ms = ui->lineEditMillisecond->text().toInt(&ok);
	//if (!ok || ms < 0)
	//{
	//	QMessageBox::critical(this, "Error", "Invalid time");
	//	return;
	//}

	//// Seek to the desired frame
	//if (!m_Decoder.seekMs(ms))
	//{
	//	QMessageBox::critical(this, "Error", "Seek failed");
	//	return;
	//}
	//// Display the frame
	//displayFrame();


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

void MainWindow::on_actionFirst_triggered()
{
	qDebug() << "on_actionFirst_triggered()";
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

	if (!filename.isEmpty()) {
		m_LastFolderOpen = QFileInfo(filename).absolutePath();
		m_First.OpenFile(filename);
	}

}

void MainWindow::on_actionSecond_triggered()
{
	qDebug() << "on_actionSecond_triggered()";
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

	if (!filename.isEmpty()) {
		m_LastFolderOpen = QFileInfo(filename).absolutePath();
		m_Second.OpenFile(filename);
	}

}

void MainWindow::on_actionThird_triggered()
{
	qDebug() << "on_actionThird_triggered()";

}

void MainWindow::on_actionFourth_triggered()
{
	qDebug() << "on_actionFourth_triggered()";

}

void MainWindow::on_actionFifth_triggered()
{
	qDebug() << "on_actionFifth_triggered()";

}

void MainWindow::on_actionSixth_triggered()
{
	qDebug() << "on_actionSixth_triggered()";

}

void MainWindow::on_actionSeventh_triggered()
{
	qDebug() << "on_actionSeventh_triggered()";

}

void MainWindow::on_actionEighth_triggered()
{
	qDebug() << "on_actionEighth_triggered()";

}