#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subtitleline.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // constructors & destructors
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(QString filename, QWidget *parent = 0);
    ~MainWindow();

    // public methods
    void loadSubtitle(QString filename);
    void reloadSubtitle();
    void saveSubtitle(QString filename);

private:
    // private attributes
    QVector<SubtitleLine> lines;
    QString subfilename;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
