#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    timer->setTimerType(Qt::PreciseTimer);
}

void Stopwatch::startTimer()
{
    timer->start();
}

int Stopwatch::returnTime()
{
    return timer->remainingTime();
}
