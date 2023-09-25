#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    About *m_pAbout;
    QString m_startStr = "Старт", m_stopStr = "Стоп";
    Stopwatch *m_pStopwatch;
    int m_lap = 1;

    QString doubleToHHMMSS(double value);

public slots:
    void Rcv_returnTime(double time);
private slots:
    void on_about_triggered();
};
#endif // MAINWINDOW_H
