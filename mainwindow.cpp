#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMinimumSize(850,500);
    setMaximumSize(850,500);
    setStyleSheet("#MainWindow{border-image:url(:/bg_img/img/welcome_bg.jpeg);}");

    ui->login->setStyleSheet("background-color: rgb(255, 251, 0); color: rgb(83, 27, 147);");
    ui->signup->setStyleSheet("background-color: rgb(255, 251, 0); color: rgb(83, 27, 147);");

    ui->input_pw->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);");
    ui->input_tel->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);");


    ui->welcome->setText("Welcome to Chattery !");
    ui->welcome->setFont(QFont("Chalkboard SE"));
    ui->welcome->setStyleSheet("color: rgb(255, 251, 0);font: 40pt");


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    room->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    room->server->show();
}

