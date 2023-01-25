#include "database.h"

Database::Database(QString db_name): dbName(db_name) {
    qDebug() << QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(hostName);
    db.setPort(port);
    db.setUserName(username);
    db.setPassword(password);
    db.setDatabaseName(dbName);

    ok();
}

bool Database::ok() {
    if (db.open()) {
        qDebug() << "Connect to the database successfully !";
        return true;
    }else {
        qDebug() << "Something is wrong !";
        QMessageBox::critical(NULL, "Connection error: ",
                             db.lastError().text());
        return false;
    }
}

