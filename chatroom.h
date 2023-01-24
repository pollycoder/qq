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


    ChatServer *server = new ChatServer();
    ChatClient *client = new ChatClient();
private:
    Ui::ChatRoom *ui;

};

#endif // CHATROOM_H
