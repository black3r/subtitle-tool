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

    void loadSubtitle(QString filename);
    void reloadSubtitle();
    void saveSubtitle(QString filename);
    QString getSubPath();
    QVector<SubtitleLine>* getLines();
    SubtitleLine* getLineByText(QString text);

private:
    QVector<SubtitleLine> lines;
    QString subpath;
};

#endif // SUBTITLES_H
