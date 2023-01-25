#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QString>
#include <QMessageBox>

class Database
{
public:
    explicit Database() = default;
    explicit Database(QString db_name);
    ~Database() { close(); }

    bool ok();                                          // Whether the database is working

    void close(){ if (db.isOpen()) db.close(); }


private:
    QSqlDatabase db;
    QString dbName;
    const int port = 3306;
    const QString hostName = "localhost";
    const QString password = "pollyjoe2003";
    const QString username = "root";
};

#endif // DATABASE_H
