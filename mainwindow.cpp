#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QString filepath, QWidget *parent) : MainWindow(parent)
{
    this->openSubtitles(filepath);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSubtitles(QString filepath) {
    this->subs = new Subtitles(filepath);
}

void MainWindow::openSubtitles(Subtitles* subs) {
    this->subs = subs;
}
