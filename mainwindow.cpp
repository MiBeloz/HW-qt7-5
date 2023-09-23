#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopwatch = new Stopwatch(this);

    ui->pb_StartStop->setText("Старт");
    ui->pb_Lap->setEnabled(false);
    ui->pb_Clear->setEnabled(false);
    ui->lb_time->setText("0.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_StartStop_clicked()
{
    stopwatch->startTimer();
}

void MainWindow::slotTimerAlarm()
{
    ui->lb_time->setText(QString::number(stopwatch->returnTime()));
}
