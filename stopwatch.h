#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <chrono>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    void startTimer();
    int returnTime();

private:
    QTimer *timer;

signals:
    void sig_remainingTimer(std::chrono::milliseconds time) {
        timer->startTimer();
    }

};

#endif // STOPWATCH_H
