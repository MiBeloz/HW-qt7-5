#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr, int interval = 100);

    void startTimer();
    void stopTimer();
    void timeout();
    void reset();

private:
    QTimer *m_pTimer;
    double m_time;
    int m_interval;

signals:
    void sig_timeout(double time);

};

#endif // STOPWATCH_H
