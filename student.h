#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student();

    QString getName() const;
    void setName(const QString &value);

    QString getLevel() const;
    void setLevel(const QString &value);

    int getTeacherId() const;
    void setTeacherId(int value);

    double getGrade() const;
    void setGrade(double value);

    int getId() const;
    void setId(int value);

private:
    int id;
    QString name;
    QString level;
    int teacherId;
    double grade;

};

#endif // STUDENT_H
