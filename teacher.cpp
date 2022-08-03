#include "teacher.h"

Teacher::Teacher()
{

}

QString Teacher::getName() const
{
    return name;
}

void Teacher::setName(const QString &value)
{
    name = value;
}

QString Teacher::getEmail() const
{
    return email;
}

void Teacher::setEmail(const QString &value)
{
    email = value;
}

int Teacher::getId() const
{
    return id;
}

void Teacher::setId(int value)
{
    id = value;
}

QString Teacher::getPassword() const
{
    return password;
}

void Teacher::setPassword(const QString &value)
{
    password = value;
}
