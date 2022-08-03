#include "teacherdb.h"

#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QVariant>

TeacherDB::TeacherDB()
{

}

bool TeacherDB::insertTeacher(const Teacher &teacher)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {

        QSqlQuery * query = new QSqlQuery(db);
        QString name = teacher.getName();
        QString email = teacher.getEmail();
        QString password = teacher.getPassword();

        QString tmp = "INSERT INTO Teachers(teacherName,teacherEmail,teacherPassword) VALUES('" + name + "','" + email + "','" + password + "')";

        if(!query->exec(tmp)) {
            return false;
        }

        delete query;
        db.close();
        return true;
    }

    return false;
}

QList<Teacher> TeacherDB::listTeacher()
{
    QList<Teacher> lista;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {

        QSqlQuery * query = new QSqlQuery(db);
        QString tmp = "SELECT id, teacherName, teacherEmail, teacherPassword FROM Teachers";

        if(query->exec(tmp)) {

            while(query->next()) {
                Teacher tmpTeacher;
                tmpTeacher.setId(query->value(0).toInt());
                tmpTeacher.setName(query->value(1).toString());
                tmpTeacher.setEmail(query->value(2).toString());
                tmpTeacher.setPassword(query->value(3).toString());

                lista.append(tmpTeacher);
            }
        }

        delete query;
        db.close();
    }

    return lista;
}

bool TeacherDB::deleteTeacher(const Teacher &teacher)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {

        QSqlQuery * query = new QSqlQuery(db);
        QString id = QString::number(teacher.getId());

        QString tmp = "DELETE FROM Teachers WHERE id = '" + id + "'";

        if(!query->exec(tmp)) {
            return false;
        }

        delete query;
        db.close();
        return true;
    }

    return false;
}

bool TeacherDB::updateTeacher(const Teacher &teacher)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {

        QSqlQuery * query = new QSqlQuery(db);
        QString id = QString::number(teacher.getId());
        QString name = teacher.getName();
        QString email = teacher.getEmail();
        QString password = teacher.getPassword();

        QString tmp = "UPDATE Teachers SET teacherName = '" + name + "', teacherEmail = '" + email + "', teacherPassword = '" + password + "' WHERE id = '" + id + "'";

        if(!query->exec(tmp)) {
            return false;
        }

        delete query;
        db.close();
        return true;
    }

    return false;
}
