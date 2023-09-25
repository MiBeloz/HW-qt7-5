#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon(":/ico/stopwatch.ico");
    this->setWindowIcon(icon);
    m_pAbout = new About(this);
    m_pAbout->setWindowIcon(icon);
    m_pStopwatch = new Stopwatch(this);

    ui->pb_StartStop->setText(m_startStr);
    ui->pb_Lap->setEnabled(false);
    ui->pb_Clear->setEnabled(false);
    //ui->lb_time->setText("00:00:00.0");
    ui->lb_time->setText("00:00.0");

    connect(m_pStopwatch, &Stopwatch::sig_timeout, this, &MainWindow::Rcv_returnTime);
    connect(ui->pb_StartStop, &QPushButton::clicked, this, [this]{
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
    });
    connect(ui->pb_Lap, &QPushButton::clicked, this, [this]{
        ui->tBr_result->append("Круг №" + QString::number(m_lap) + ", Время: " + doubleToHHMMSS(m_pStopwatch->getLap()));
        m_lap++;
    });
    connect(ui->pb_Clear, &QPushButton::clicked, this, [this]{
        m_pStopwatch->stopTimer();
        m_pStopwatch->reset();
        //ui->lb_time->setText("00:00:00.0");
        ui->lb_time->setText("00:00.0");
        ui->pb_StartStop->setText(m_startStr);
        ui->pb_Lap->setEnabled(false);
        ui->pb_Clear->setEnabled(false);
        m_lap = 1;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::doubleToHHMMSS(double value)
{
    int valueInt = static_cast<int>(value);
    QString result;
    //QString h = QString::number(valueInt / 3600);
    QString m = QString::number((valueInt % 3600) / 60);
    QString s = QString::number(valueInt % 60);
    //QString hh = QString(2 - h.length(), '0') + h;
    QString mm = QString(2 - m.length(), '0') + m;
    QString ss = QString(2 - s.length(), '0') + s;
    QString difference = QString::number(static_cast<int>((value - valueInt) * 10));

    //return hh + ':' + mm + ":" + ss + "." + difference;
    return mm + ":" + ss + "." + difference;
}

void MainWindow::Rcv_returnTime(double time)
{

    ui->lb_time->setText(doubleToHHMMSS(time));
}

void MainWindow::on_about_triggered()
{
    m_pAbout->setModal(true);
    m_pAbout->show();
}

