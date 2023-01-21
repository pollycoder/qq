#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QWidget>

namespace Ui {
class ChatClient;
}

class ChatClient : public QWidget
{
    Q_OBJECT

public:
    explicit ChatClient(QWidget *parent = nullptr);
    ~ChatClient();

private:
    Ui::ChatClient *ui;
};

#endif // CHATCLIENT_H
