#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    QPixmap pixmap(":/png/stopwatch.png");
    ui->lb_ico->setPixmap(pixmap);

    ui->lb_about->setText("\tСекундомер\n"
                       "\tv" + QString::number(PROG_VER_MAJOR) + '.' + QString::number(PROG_VER_MINOR) + "\n"
                       "\n"
                       "\tБелозеров Михаил");
}

About::~About()
{
    delete ui;
}
