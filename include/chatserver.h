#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QByteArray>
#include <QMessageBox>

namespace Ui {
class ChatServer;
}

class ChatServer : public QWidget
{
    Q_OBJECT

public:
    explicit ChatServer(QWidget *parent = nullptr);
    ~ChatServer();

    void start_server();							// Start when a new chat is on
    void close_server();							// Close the server when the chat is over
    void send_message(const QByteArray &msg);		// Send messages to clients
    QTcpServer* getServer() { return server; }

public slots:
    void slot_newConnection();                      // When new client connects the server, newConnection() signal
    void slot_disconnected();                       // When a client is offline, disconnected() signal
    void slot_readyRead();                          // When a client sends message, readyRead() signal

private:
    Ui::ChatServer *ui;
    QTcpServer *server;
    QVector<QTcpSocket*> clients;

};

#endif // CHATSERVER_H
