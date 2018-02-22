/************************************************************************
**
**  Copyright (C) 2018  spdevapp <spdevapp@joara.com>
**
**  This file is part of Aries.
**
**  Aries is video player for ffmepg.
**
*************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ffmpegQT341/QVideoDecoder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void on_actionOpen_triggered();
	void on_actionExit_triggered();

	void on_pushButtonNextFrame_clicked();
	void on_pushButtonSeekMillisecond_clicked();
	void on_pushButtonSeekFrame_clicked();

private:

	void ReadSetting();
	void WriteSetting();

	void InitUI();
	void ConnectSignalsToSlots();

	void changeEvent(QEvent *e);

	// Helper

	void image2Pixmap(QImage &img, QPixmap &pixmap);

	// Decoder demo
	void displayFrame();
	void loadVideo(QString fileName);
	void errLoadVideo();
	bool checkVideoLoadOk();
	void nextFrame();

	QVideoDecoder m_Decoder;

	QString		m_LastFolderOpen;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
