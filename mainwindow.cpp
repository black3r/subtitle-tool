#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "semiautomovedialog.h"

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
    this->openSubtitles(new Subtitles(filepath));
}

void MainWindow::openSubtitles(Subtitles* subs) {
    this->subs = subs;
    this->ui->subPathLabel->setText(this->subs->getSubPath());
}

void MainWindow::on_semiAutoButton_clicked()
{
    SemiAutoMoveDialog* dialog = new SemiAutoMoveDialog(this->subs);
    connect(dialog, SIGNAL(finished(int)), dialog, SLOT(deleteLater()));
    dialog->exec();
}

void MainWindow::on_saveQuitButton_clicked()
{
    this->subs->save();
    this->close();
}

void MainWindow::on_actionSave_triggered()
{
    this->subs->save();
}
