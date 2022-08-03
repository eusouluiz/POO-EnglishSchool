#ifndef NEWSTUDENT_H
#define NEWSTUDENT_H

#include <QDialog>
#include <QList>
#include "studentdb.h"

namespace Ui {
class NewStudent;
}

class NewStudent : public QDialog
{
    Q_OBJECT

public:
    explicit NewStudent(QWidget *parent = nullptr, QList<Teacher> * teachers = new QList<Teacher>);
    ~NewStudent();

private slots:
    void on_buttonBox_2_accepted();

    void on_buttonBox_2_rejected();

private:
    Ui::NewStudent *ui;

    StudentDB * stuDB;
    QList<Teacher> * teacherList;
};

#endif // NEWSTUDENT_H
