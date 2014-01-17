#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QString filename, QWidget *parent) : MainWindow(parent)
{
    this->loadSubtitle(filename);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadSubtitle(QString filename) {
    this->subfilename = filename;
    this->reloadSubtitle();
}

void MainWindow::reloadSubtitle() {
    QFile* subfile = new QFile(subfilename);
    if (subfile->open(QFile::ReadOnly)) {
        QTextStream in(subfile);
        // NOTE: I expect input to be in CP-1250
        // (This program is mainly meant for cz/sk subtitles on Windows)
        // TODO: Provide auto detection or picker for encoding.
        in.setCodec(QTextCodec::codecForName("CP1250"));
        // NOTE: I only support SRT file-format now
        // TODO: Implement other format support (possibly through plug-ins)
        int ctr = 0;
        QString id_str;
        QString timestamps_str;
        QVector<QString> subtitle_lines;
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line == "") {
                ctr = 0;
                SubtitleLine line(id_str, timestamps_str, subtitle_lines);
                this->lines.push_back(line);
            }
            else {
                if (ctr == 0) id_str = line;
                else if (ctr == 1) timestamps_str = line;
                else subtitle_lines.push_back(line);
                ctr++;
            }
        }
        subfile->close();
    } else {
        std::cerr << "File could not be opened!" << std::endl;
    }
    delete subfile;
}
