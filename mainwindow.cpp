#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QString filename, QWidget *parent) : MainWindow(parent)
{
    this->subfilename = filename;
}

MainWindow::~MainWindow()
{
    delete ui;
}
