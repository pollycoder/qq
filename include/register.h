#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>

#include "database.h"
#include "utils.h"

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
    void slot_clear();
    void slot_selectAvatar();

private:
    Ui::Register *ui;
    Database *client_db;
    QString tel ;
    QString username;
    QString password;
    QString confirm_pw;
    QString pathAvatar;
};

#endif // REGISTER_H
