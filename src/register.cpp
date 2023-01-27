#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setMinimumSize(850,500);
    setMaximumSize(850,500);
    QFile file = QFile(":/qss/register.qss");
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());
}

Register::~Register()
{
    delete ui;
}

void Register::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
