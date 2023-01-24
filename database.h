#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QString>

class Database
{
public:
    Database() = default;
    Database(QString db_name);
    ~Database() = delete;

    bool ok();                                  // Whether the database is working


private:
    QSqlDatabase db;
    QString dbName;
    const int port = 3306;
    const QString hostName = "localhost";
    const QString password = "pollyjoe2003";
    const QString username = "root";
};

#endif // DATABASE_H
