#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

#define PROG_VER_MAJOR 1
#define PROG_VER_MINOR 2

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
