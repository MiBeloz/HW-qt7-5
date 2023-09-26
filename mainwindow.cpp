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
    ui->lb_time->setText("00:00.0");

    connect(m_pStopwatch, &Stopwatch::sig_timeout, this, &MainWindow::Rcv_returnTime);
    connect(ui->pb_StartStop, &QPushButton::clicked, this, [this]{
        if (ui->pb_StartStop->text() == m_startStr) {
            m_pStopwatch->startTimer();
            ui->pb_StartStop->setText(m_stopStr);
            ui->pb_Lap->setEnabled(true);
        }
        else {
            m_pStopwatch->stopTimer();
            ui->pb_StartStop->setText(m_startStr);
            ui->pb_Lap->setEnabled(false);
        }
    });
    connect(ui->pb_Lap, &QPushButton::clicked, this, [this]{
        ui->tBr_result->append("Круг №" + QString::number(m_lap) + ", Время: " + m_pStopwatch->getLap());
        m_lap++;
        ui->pb_Clear->setEnabled(true);
    });
    connect(ui->pb_Clear, &QPushButton::clicked, this, [this]{
        m_pStopwatch->reset();
        ui->lb_time->setText("00:00.0");
        m_lap = 1;
        ui->pb_Clear->setEnabled(false);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Rcv_returnTime(QString time)
{
    ui->pb_Clear->setEnabled(true);
    ui->lb_time->setText(time);
}

void MainWindow::on_about_triggered()
{
    m_pAbout->setModal(true);
    m_pAbout->show();
}

