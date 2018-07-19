#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
/*
    Code taken from https://doc.qt.io/Qt-5/qtsql-cachedtable-example.html
*/

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/testdatabase.db");

    if (!db.open()) {
        return -1;
    }

    QSqlQuery query;
    query.exec("create table person (id int primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(101, 'Danny', 'Young')");

    return 0;
}
