#include "chatbubble.h"
#include "ui_chatbubble.h"

ChatBubble::ChatBubble(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatBubble)
{
    ui->setupUi(this);
    QWebEngineView *view = new QWebEngineView(parent);
    view->load(QUrl(":/html/chatbox_self.html"));
    view->show();
}

ChatBubble::~ChatBubble()
{
    delete ui;
}
