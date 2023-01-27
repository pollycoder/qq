#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client_db = new Database("client_info");

    // Set the style sheet for main window
    setMinimumSize(850,500);
    setMaximumSize(850,500);

    QFile file = QFile(":/qss/mainwindow.qss");
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());
    ui->input_pw->setEchoMode(QLineEdit::Password);
    connect(ui->login, SIGNAL(clicked()), this, SLOT(slot_login()));
    connect(ui->signup, SIGNAL(clicked()), this, SLOT(slot_register()));
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::slot_login() {
    QString tel = ui->input_tel->text();
    QString password = ui->input_pw->text();
    QString findUser = QString("SELECT * FROM clients WHERE tel='%1'").arg(tel);
    QSqlQuery query(findUser);
    if (query.first()) {
        QString username = query.value("username").toString();
        QString realPassword = query.value("password").toString();
        if (password == realPassword) {
            QString welcomeMsg = "Hello," + username + ",\nwelcome to CHATTERY !!!";
            QMessageBox::information(NULL, "Welcome !", welcomeMsg);
            this->close();
            this->client->setUsername(username);
            this->room->client->setUsername(username);
            this->room->show();
        } else {
            QMessageBox::critical(NULL, "Password incorrect !!!",
                                  "The password is incorrect ! Please try again !");
        }
    } else {
        QMessageBox::critical(NULL, "User not exist !!",
                              "Cannot find the user, please sign up an account !");
    }
}

void MainWindow::slot_register() {
    regwindow->show();
}
