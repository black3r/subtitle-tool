#include "subtitleline.h"
#include <QStringList>
#include <QTime>

SubtitleLine::SubtitleLine() {

}

SubtitleLine::SubtitleLine(QString id, QString timestamps, QVector<QString> lines) {
    this->id = id;
    this->timestamps = timestamps;
    this->lines = lines;

    QStringList stamps = this->timestamps.split(" ");
    this->msecStart = SubtitleLine::toMsecs(stamps[0]);
    this->msecStop = SubtitleLine::toMsecs(stamps[2]);
}

long SubtitleLine::toMsecs(QString timestamp) {
    QTime time = QTime::fromString(timestamp, "hh:mm:ss,zzz");
    return time.msecsSinceStartOfDay();
}

QString SubtitleLine::toTimestamp(long msecs) {
    QTime time = QTime::fromMSecsSinceStartOfDay(msecs);
    return time.toString("hh:mm:ss,zzz");
}

QString SubtitleLine::start() {
    return SubtitleLine::toTimestamp(this->msecStart);
}

QString SubtitleLine::stop() {
    return SubtitleLine::toTimestamp(this->msecStop);
}

QString SubtitleLine::getFormatted() {
    QString sb;
    sb += id + "\n";
    sb += this->start() + " --> " + this->stop() + "\n";
    for (auto line : lines) sb += line + "\n";
    sb += "\n";
    return sb;
}

QString SubtitleLine::getOneLine() {
    QString result = "";
    for (QString line : lines) {
        result += line + " ";
    }
    return result;
}

void SubtitleLine::move(int msecs) {
    this->msecStart += msecs;
    this->msecStop += msecs;
}

void SubtitleLine::stretch(int num, int den) {
    this->msecStart = (this->msecStart * num) / den;
    this->msecStop = (this->msecStop * num) / den;
}

long SubtitleLine::getMsecStart() {
    return msecStart;
}

long SubtitleLine::getMsecStop() {
    return msecStop;
}
