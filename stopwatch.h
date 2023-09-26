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
    QString getLap();

private:
    QTimer *m_pTimer;
    int m_interval;
    double m_time;
    double m_duration;

    QString convertTimeToStr(double time);

signals:
    void sig_timeout(QString time);

};

#endif // STOPWATCH_H
