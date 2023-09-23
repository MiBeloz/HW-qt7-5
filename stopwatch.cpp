#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent, int interval) : QObject(parent), m_interval(interval)
{
    m_time = 0.0;
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
    sig_timeout(m_time);
}

void Stopwatch::reset()
{
    m_time = 0.0;
}
