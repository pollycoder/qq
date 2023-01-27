#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QFile>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    void paintEvent(QPaintEvent *);

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
