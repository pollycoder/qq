#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    client_db = new Database("client_info");

    setMinimumSize(700,500);
    setMaximumSize(700,500);
    QFile file = QFile(":/qss/register.qss");
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());

    connect(ui->signup, SIGNAL(clicked()), this, SLOT(slot_register()));
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

void Register::slot_register() {
    QString tel = ui->input_tel->text();
    QString username = ui->input_user->text();
    QString password = ui->input_pw->text();
    QString confirm_pw = ui->input_confirmpw->text();

    // Make sure all the blanks are filled in
    if (tel.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(NULL, "Info not completed !", "Please fill in all the information !");
    } else if (confirm_pw.isEmpty()) {
        QMessageBox::warning(NULL, "Password not confirmed !", "Please confirm your password !");
    } else if (password != confirm_pw) {
        QMessageBox::warning(NULL, "Different password !", "The two passwords are different !");
    } else {
        // Make sure this is a new user
        QString insert =
                QString("INSERT INTO client_info.clients (tel, username, password) VALUES ('%1','%2','%3')")
                .arg(tel).arg(username).arg(password);
        QString check = QString("SELECT * FROM client_info.clients WHERE tel='%1' ").arg(tel);
        QSqlQuery query;
        if (query.exec(insert)) {
            QMessageBox::information(NULL, "Succeed !", "Congratulations, you have signed up as our user, enjoy your chatting !");
        } else if (query.exec(check) && query.first()) {
            QMessageBox::warning(NULL, "User exists !", "The telephone number exists !");
        } else {
            QMessageBox::warning(NULL, "Something is wrong !", "Something bad happens, please try again.");
        }
    }
    ui->input_tel->clear();
    ui->input_user->clear();
    ui->input_pw->clear();
    ui->input_confirmpw->clear();
}
