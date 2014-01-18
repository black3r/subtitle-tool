#ifndef SUBTITLES_H
#define SUBTITLES_H

#include <QString>
#include <QVector>
#include "subtitleline.h"

class Subtitles
{
public:
    // constructors and destructors
    Subtitles();
    Subtitles(QString filename);

    // public methods
    void loadSubtitle(QString filename);
    void reloadSubtitle();
    void saveSubtitle(QString filename);

private:
    // private attributes
    QVector<SubtitleLine> lines;
    QString subfilename;
};

#endif // SUBTITLES_H
