#ifndef CHATROOM_H
#define CHATROOM_H

#include <QWidget>

#include "chatserver.h"
#include "chatclient.h"

namespace Ui {
class ChatRoom;
}

class ChatRoom : public QWidget
{
    Q_OBJECT

public:
    explicit ChatRoom(QWidget *parent = nullptr);
    ~ChatRoom();

private slots:
    void slot_sendMessage();
    void slot_displayMessage(QString msg);
    void slot_clearInput();

    signals:
    void send(QString);

public:
    ChatServer *server = new ChatServer();
    ChatClient *client = new ChatClient();
    QVector<ChatClient*> friends;

    Ui::ChatRoom* getUi() { return ui; }
private:
    Ui::ChatRoom *ui;

};

#endif // CHATROOM_H
