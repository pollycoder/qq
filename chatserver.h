#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QWidget>

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
};

#endif // CHATSERVER_H
