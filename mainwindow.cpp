#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Set the style sheet for main window
    setMinimumSize(850,500);
    setMaximumSize(850,500);
    //setStyleSheet("#MainWindow{border-image:url(:/img/welcome_bg.jpeg);}");

    QFile file = QFile(":/qss/mainwindow.qss");
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());

}

MainWindow::~MainWindow()
{
    delete ui;
}


// !!!!-------------------------------------------------------------------------------------------------------------!!!!
// !!!!-------------------------------------------------- Warning --------------------------------------------------!!!!
// !!!!-------------------------------------------------------------------------------------------------------------!!!!
// Just for test !!!
// No removing before finishing the project !!!
// Remove immediately when finish the project !!!
void MainWindow::on_pushButton_clicked()
{
    room->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    room->server->show();
}

