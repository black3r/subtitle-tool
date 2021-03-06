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
    void move(int msecs);
    void stretch(int num, int den);
    long long getMsecStart();
    long long getMsecStop();

    static long long toMsecs(QString timestamp);
    static QString toTimestamp(long long msecs);

private:
    QString id;
    QString timestamps;
    long long msecStart;
    long long msecStop;
    QVector<QString> lines;
};

#endif // SUBTITLELINE_H
