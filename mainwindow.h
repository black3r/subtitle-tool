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
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(QString filepath, QWidget *parent = 0);
    ~MainWindow();

    void openSubtitles(Subtitles* subs);
    void openSubtitles(QString filepath);

private slots:
    void on_semiAutoButton_clicked();
    void on_saveQuitButton_clicked();
    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    Subtitles* subs;
};

#endif // MAINWINDOW_H
