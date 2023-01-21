#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

namespace Ui {
class ChatServer;
}

class ChatServer : public QWidget
{
    Q_OBJECT

public:
    explicit ChatServer(QWidget *parent = nullptr);
    ~ChatServer();

private:
    Ui::ChatServer *ui;
    QTcpServer *server;
    QList<QTcpSocket*> clients;

};

#endif // CHATSERVER_H
