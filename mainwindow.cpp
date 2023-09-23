#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pAbout = new About(this);
    m_pStopwatch = new Stopwatch(this);

    ui->pb_StartStop->setText(m_startStr);
    ui->pb_Lap->setEnabled(false);
    ui->pb_Clear->setEnabled(false);
    ui->lb_time->setText("0");

    connect(m_pStopwatch, &Stopwatch::sig_timeout, this, &MainWindow::Rcv_returnTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Rcv_returnTime(double time)
{
    ui->lb_time->setText(QString::number(time));
}

void MainWindow::on_pb_StartStop_clicked()
{
    if (ui->pb_StartStop->text() == m_startStr) {
        m_pStopwatch->startTimer();
        ui->pb_StartStop->setText(m_stopStr);
        ui->pb_Lap->setEnabled(true);
        ui->pb_Clear->setEnabled(true);
    }
    else {
        m_pStopwatch->stopTimer();
        ui->pb_StartStop->setText(m_startStr);
        ui->pb_Lap->setEnabled(false);
    }
}


void MainWindow::on_pb_Lap_clicked()
{
    double time = ui->lb_time->text().toDouble() - m_duration;
    ui->tBr_result->append("Круг №" + QString::number(m_lap) + ", Время: " + QString::number(time));
    m_lap++;
    m_duration = ui->lb_time->text().toDouble();
}


void MainWindow::on_pb_Clear_clicked()
{
    m_pStopwatch->stopTimer();
    m_pStopwatch->reset();
    ui->lb_time->setText("0");
    ui->pb_StartStop->setText(m_startStr);
    ui->pb_Lap->setEnabled(false);
    ui->pb_Clear->setEnabled(false);
    m_lap = 1;
    m_duration = 0.0;
}


void MainWindow::on_about_triggered()
{
    m_pAbout->setModal(true);
    m_pAbout->show();
}

