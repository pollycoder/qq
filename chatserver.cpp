#include "chatserver.h"
#include "ui_chatserver.h"

ChatServer::ChatServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatServer)
{
    ui->setupUi(this);
}

ChatServer::~ChatServer()
{
    delete ui;
}
