#ifndef TEACHER_H
#define TEACHER_H

#include <QString>

class Teacher
{
public:
    Teacher();

    QString getName() const;
    void setName(const QString &value);


    QString getPassword() const;
    void setPassword(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    int getId() const;
    void setId(int value);

private:
    int id;
    QString name;
    QString email;
    QString password;
};

#endif // TEACHER_H
