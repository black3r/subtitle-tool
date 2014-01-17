#ifndef SUBTITLELINE_H
#define SUBTITLELINE_H

#include <QString>
#include <QTime>
#include <QVector>

class SubtitleLine
{
public:
    //constructors and destructors
    SubtitleLine();
    SubtitleLine(QString id, QString timestamps,
                 QVector<QString> lines);

    // public methods
    QString start();
    QString stop();
    QString getFormatted();

    // public static methods
    static int toMsecs(QString timestamp);
    static QString toTimestamp(int msecs);

private:
    // private attributes
    QString id;
    QString timestamps;
    int msecStart;
    int msecStop;
    QVector<QString> lines;
};

#endif // SUBTITLELINE_H
