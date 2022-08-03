#include "student.h"

Student::Student()
{
    this->id = 0;
}

QString Student::getName() const
{
    return name;
}

void Student::setName(const QString &value)
{
    name = value;
}

QString Student::getLevel() const
{
    return level;
}

void Student::setLevel(const QString &value)
{
    level = value;
}

int Student::getTeacherId() const
{
    return teacherId;
}

void Student::setTeacherId(int value)
{
    teacherId = value;
}

double Student::getGrade() const
{
    return grade;
}

void Student::setGrade(double value)
{
    grade = value;
}

int Student::getId() const
{
    return id;
}

void Student::setId(int value)
{
    id = value;
}
