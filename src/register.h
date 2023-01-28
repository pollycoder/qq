#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include <QMessageBox>
#include "database.h"

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

private slots:
    void slot_register();

private:
    Ui::Register *ui;
    Database *client_db;
};

#endif // REGISTER_H
