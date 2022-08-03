#include "studentdb.h"

#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QVariant>

StudentDB::StudentDB()
{

}

bool StudentDB::insertStudent(const Student &student)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {

        QSqlQuery * query = new QSqlQuery(db);
        QString name = student.getName();
        QString level = student.getLevel();
        QString teacherId = QString::number(student.getTeacherId());
        QString grade = QString::number(student.getGrade());

        QString tmp = "INSERT INTO Students(studentName,level,teacherId,grade) VALUES('" + name + "','" + level + "','" + teacherId + "','" + grade + "')";

        if(!query->exec(tmp)) {
            return false;
        }

        delete query;
        db.close();
        return true;
    }

    return false;
}

QList<Student> StudentDB::listStudents(QString selection)
{
    QList<Student> lista;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {
        QSqlQuery * query = new QSqlQuery(db);

        QString tmp;
        if (selection == nullptr) {
            tmp = "SELECT id, studentName, level, teacherId, grade FROM Students";
        } else {
            tmp = "SELECT id, studentName, level, teacherId, grade FROM Students WHERE " + selection;
        }

        if(query->exec(tmp)) {

            while(query->next()) {
                Student tmpStudent;
                tmpStudent.setId(query->value(0).toInt() );
                tmpStudent.setName(query->value(1).toString());
                tmpStudent.setLevel(query->value(2).toString());
                tmpStudent.setTeacherId(query->value(3).toInt());
                tmpStudent.setGrade(query->value(4).toDouble());


                lista.append(tmpStudent);
            }
        }

        delete query;
        db.close();
    }

    return lista;
}

QList<Student> StudentDB::listStudentsByTeacher(Teacher &currentTeacher)
{
    return this->listStudents( "teacherId = " + QString::number(currentTeacher.getId()) );
}

bool StudentDB::deleteStudent(const Student &student)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {

        QSqlQuery * query = new QSqlQuery(db);
        QString id = QString::number(student.getId());

        QString tmp = "DELETE FROM Students WHERE id = '" + id + "'";

        if(!query->exec(tmp)) {
            return false;
        }

        delete query;
        db.close();
        return true;
    }

    return false;
}

void StudentDB::deleteStudentById(int id)
{
    Student tmpStudent;
    tmpStudent.setId(id);
    this->deleteStudent(tmpStudent);
}

bool StudentDB::updateStudent(const Student &student)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {

        QSqlQuery * query = new QSqlQuery(db);
        QString id = QString::number(student.getId());
        QString name = student.getName();
        QString level = student.getLevel();
        QString teacherId = QString::number(student.getTeacherId());
        QString grade = QString::number(student.getGrade());

        QString tmp = "UPDATE Students SET studentName = '" + name + "', level = '" + level + "', teacherId = '" + teacherId + "', grade = '" + grade + "' WHERE id = '" + id + "'";

        if(!query->exec(tmp)) {
            return false;
        }

        delete query;
        db.close();
        return true;
    }

    return false;
}

bool StudentDB::getStudentById(int id, Student * tmpStudent)
{
    QSqlDatabase db;
    bool exec = false;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../EnglishSchool/database.db");

    if(db.open()) {
        QSqlQuery * query = new QSqlQuery(db);

        QString tmp = "SELECT id, studentName, level, teacherId, grade FROM Students WHERE id = " + QString::number(id);

        if(query->exec(tmp)) {

            while(query->next()) {
                tmpStudent->setId(query->value(0).toInt());
                tmpStudent->setName(query->value(1).toString());
                tmpStudent->setLevel(query->value(2).toString());
                tmpStudent->setTeacherId(query->value(3).toInt());
                tmpStudent->setGrade(query->value(4).toDouble());
            }

        }

        if (tmpStudent->getName().size() > 0){
            exec = true;
        } else {
            exec = false;
        }

        delete query;
        db.close();
    }

    return exec;
}
