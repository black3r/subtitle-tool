#ifndef SUBTITLELINE_H
#define SUBTITLELINE_H

#include <QString>
#include <QVector>

class SubtitleLine
{
public:
    SubtitleLine();
    SubtitleLine(QString id, QString timestamps,
                 QVector<QString> lines);

    QString start();
    QString stop();
    QString getFormatted();
    QString getOneLine();

    static int toMsecs(QString timestamp);
    static QString toTimestamp(int msecs);

private:
    QString id;
    QString timestamps;
    int msecStart;
    int msecStop;
    QVector<QString> lines;
};

#endif // SUBTITLELINE_H
