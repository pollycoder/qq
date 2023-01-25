#include "mainwindow.h"
#include "database.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    Database *db = new Database("test");
    QSqlQuery query;
    query.exec("create table student(id int primary key, name varchar(255), age int, score int);");




    w.show();
    return a.exec();
}
