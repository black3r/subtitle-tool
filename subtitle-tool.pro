#-------------------------------------------------
#
# Project created by QtCreator 2014-01-17T21:22:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = subtitle-tool
TEMPLATE = app
QMAKE_CXXFLAGS += -std=gnu++11


SOURCES += main.cpp\
        mainwindow.cpp \
    subtitleline.cpp \
    subtitles.cpp \
    semiautomovedialog.cpp

HEADERS  += mainwindow.h \
    subtitleline.h \
    subtitles.h \
    semiautomovedialog.h

FORMS    += mainwindow.ui \
    semiautomovedialog.ui
