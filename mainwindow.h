#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subtitleline.h"
#include "subtitles.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // constructors & destructors
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(QString filepath, QWidget *parent = 0);
    ~MainWindow();

    void openSubtitles(Subtitles* subs);
    void openSubtitles(QString filepath);

private:
    // private attributes
    Ui::MainWindow *ui;
    Subtitles* subs;
};

#endif // MAINWINDOW_H
