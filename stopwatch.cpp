#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent, int interval) : QObject(parent), m_interval(interval), m_time(0.0), m_duration(0.0) {
    m_pTimer = new QTimer(this);
    m_pTimer->setTimerType(Qt::PreciseTimer);
    m_pTimer->setInterval(m_interval);

    connect(m_pTimer, &QTimer::timeout, this, &Stopwatch::timeout);
}

void Stopwatch::startTimer()
{
    m_pTimer->start();
}

void Stopwatch::stopTimer()
{
    m_pTimer->stop();
}

void Stopwatch::timeout()
{
    m_time += 0.1;
    emit sig_timeout(convertTimeToStr(m_time));
}

void Stopwatch::reset()
{
    m_time = 0.0;
    m_duration = 0.0;
}

QString Stopwatch::getLap()
{
    double result = m_time - m_duration;
    m_duration = m_time;
    return convertTimeToStr(result);
}

QString Stopwatch::convertTimeToStr(double time) {
    QString m = QString::number((static_cast<int>(time) % 3600) / 60);
    QString s = QString::number(static_cast<int>(time) % 60);
    QString mm = QString(2 - m.length(), '0') + m;
    QString ss = QString(2 - s.length(), '0') + s;
    QString ms = QString::number(static_cast<int>(((time - static_cast<int>(time)) * 100) / 10));
    return mm + ":" + ss + "." + ms;
}
