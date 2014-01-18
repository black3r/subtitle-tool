#include "subtitles.h"
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <iostream>

Subtitles::Subtitles()
{

}

Subtitles::Subtitles(QString filename) {
    this->loadSubtitle(filename);
}

void Subtitles::loadSubtitle(QString filename) {
    this->subpath = filename;
    this->reloadSubtitle();
}

void Subtitles::reloadSubtitle() {
    QFile* subfile = new QFile(subpath);
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
                subtitle_lines.clear();
            }
            else {
                if (ctr == 0) id_str = line;
                else if (ctr == 1) timestamps_str = line;
                else subtitle_lines.push_back(line);
                ctr++;
            }
        }
        if (ctr != 0) {
            SubtitleLine line(id_str, timestamps_str, subtitle_lines);
            this->lines.push_back(line);
        }
        subfile->close();
    } else {
        std::cerr << "File could not be opened!" << std::endl;
    }
    delete subfile;
}

void Subtitles::saveSubtitle(QString filename) {
    QFile* subfile = new QFile(filename);
    if (subfile->open(QFile::WriteOnly)) {
        QTextStream out(subfile);
        // NOTE: Look above if you want to know why cp1250
        out.setCodec(QTextCodec::codecForName("CP1250"));
        for (SubtitleLine line : lines) {
            out << line.getFormatted();
        }
        subfile->close();
    }
    delete subfile;
}

QString Subtitles::getSubPath() {
    return this->subpath;
}
