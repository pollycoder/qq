#ifndef CHATBUBBLE_H
#define CHATBUBBLE_H

#include <QWidget>

namespace Ui {
class ChatBubble;
}

class ChatBubble : public QWidget
{
    Q_OBJECT

public:
    explicit ChatBubble(QWidget *parent = nullptr);
    ~ChatBubble();

private:
    Ui::ChatBubble *ui;
};

#endif // CHATBUBBLE_H
