#include "chatbubble.h"
#include "ui_chatbubble.h"

ChatBubble::ChatBubble(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatBubble)
{
    ui->setupUi(this);
}

ChatBubble::~ChatBubble()
{
    delete ui;
}
