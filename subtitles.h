#ifndef SUBTITLES_H
#define SUBTITLES_H

#include <QString>
#include <QVector>
#include "subtitleline.h"

class Subtitles
{
public:
    Subtitles();
    Subtitles(QString filename);

    void load(QString filename);
    void reloadSubtitle();
    void save();
    void saveAs(QString filename);
    QString getSubPath();
    QVector<SubtitleLine>* getLines();
    SubtitleLine* getLineByText(QString text);

private:
    QVector<SubtitleLine> lines;
    QString subpath;
};

#endif // SUBTITLES_H
