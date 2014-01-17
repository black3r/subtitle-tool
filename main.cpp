#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>

#define WRONG_NUMBER_OF_PARAMETERS_ERROR 1
#define NON_EXISTENT_FILE_ERROR 2
#define NON_EXISTENT_DIRECTORY_ERROR 3
#define NO_SUBTITLE_FILE_FOUND_ERROR 4

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        // NOTE: Currently I do not have a file picker ready. So I have to expect a file name in command line arguments.
        // TODO: Add function to start with no file open and open file with FilePicker
        cout << "Wrong number of parameters. Read manual" << endl;
        return WRONG_NUMBER_OF_PARAMETERS_ERROR;
    } else {
        QString filename(argv[1]);
        QFileInfo videoFile(filename);
        if (!videoFile.exists()) {
            cout << "Targeted file does not exist! Read manual" << endl;
            return NON_EXISTENT_FILE_ERROR;
        }
        QString basename = videoFile.baseName();
        QDir dir = videoFile.absoluteDir();
        if (!dir.exists()) {
            cout << "You are in a non-existent directory! This should not happen" << endl;
            return NON_EXISTENT_DIRECTORY_ERROR;
        }
        QDirIterator it(dir, QDirIterator::Subdirectories);
        QString subfilename = "";
        while (it.hasNext()) {
            it.next();
            QFileInfo subfile = it.fileInfo();
            if (subfile.exists() && subfile.suffix() == "srt") {
                if (subfile.baseName().startsWith(basename,Qt::CaseInsensitive)) {
                    subfilename = subfile.fileName();
                }
            }
        }
        if (subfilename == "") {
            cout << "No correct subtitle file found! Exiting" << endl;
            return NO_SUBTITLE_FILE_FOUND_ERROR;
        }
        QApplication a(argc, argv);
        MainWindow w(subfilename);
        w.show();

        return a.exec();
    }
}
