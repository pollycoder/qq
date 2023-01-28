#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    // Connect to the database of client info
    client_db = new Database("client_info");

    // Set the style and layout of the widget
    setMinimumSize(700,500);
    setMaximumSize(700,500);
    QString qssDir = ":/qss/register.qss";
    SetStyleSheet(this, qssDir);
    ui->input_pw->setEchoMode(QLineEdit::Password);
    ui->input_confirmpw->setEchoMode(QLineEdit::Password);

    // Connect signals and slots
    connect(ui->signup, SIGNAL(clicked()), this, SLOT(slot_register()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(slot_clear()));
    connect(ui->avatar, SIGNAL(clicked()), SLOT(slot_selectAvatar()));
}

Register::~Register()
{
    delete ui;
}


/*****************************************************
 * Rewrite the paintEvent function
 *  According to the document from Qt, the qss file for
 *  QWidget sub-class won't take effect unless the paint-
 *  Event function is rewritten.
 *****************************************************/
void Register::paintEvent(QPaintEvent *) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


/*****************************************************
 * Register a new user
 *  1. Input information: name, telephone number, password
 *  2. Check whether all the blanks are filled in
 *  3. Make sure this is a new user
 *  4. Load the avatar
 *****************************************************/
void Register::slot_register() {
    // Input information
    tel = ui->input_tel->text();
    username = ui->input_user->text();
    password = ui->input_pw->text();
    confirm_pw = ui->input_confirmpw->text();
    // Input the image
    QByteArray data;
    QFile *file=new QFile(pathAvatar);
    file->open(QIODevice::ReadOnly);
    data = file->readAll();
    file->close();
    QVariant var(data);

    // Input the text information
    // Make sure all the blanks are filled in
    if (tel.isEmpty() || username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(NULL, "Info not completed !", "Please fill in all the information !");
    } else if (confirm_pw.isEmpty()) {
        QMessageBox::warning(NULL, "Password not confirmed !", "Please confirm your password !");
    } else if (password != confirm_pw) {
        QMessageBox::warning(NULL, "Different password !", "The two passwords are different !");
    } else {
        // Make sure this is a new user
        QString insert = QString("INSERT INTO client_info.clients (tel, username, password, avatar) VALUES (?,?,?,?)");
        QString check = QString("SELECT * FROM client_info.clients WHERE tel='%1' ").arg(tel);
        QSqlQuery query;
        query.prepare(insert);
        query.addBindValue(tel);
        query.addBindValue(username);
        query.addBindValue(password);
        query.addBindValue(var);
        if (query.exec()) {
            QMessageBox::information(NULL, "Succeed !", "Congratulations, you have signed up as our user, enjoy your chatting !");
        } else if (query.exec(check) && query.first()) {
            QMessageBox::warning(NULL, "User exists !", "The telephone number exists !");
        } else {
            QMessageBox::warning(NULL, "Something is wrong !", "Something bad happens, please try again.");
        }
    }
    slot_clear();
}


/*****************************************************
 * Register a new user
 *  1. Input information: name, telephone number, password
 *  2. Check whether all the blanks are filled in
 *  3. Make sure this is a new user
 *****************************************************/
void Register::slot_clear() {
    ui->input_tel->clear();
    ui->input_user->clear();
    ui->input_pw->clear();
    ui->input_confirmpw->clear();
}


/*****************************************************
 * Choose a new avatar
 *****************************************************/
void Register::slot_selectAvatar() {
    pathAvatar = QFileDialog::getOpenFileName(this, tr("Open File"),
                                              "/home",
                                              tr("Images (*.jpg)"));
    QString stylesheet = QString("border-image: url(%1);").arg(pathAvatar);
    ui->avatar->setStyleSheet(stylesheet);
}
