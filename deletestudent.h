#ifndef DELETESTUDENT_H
#define DELETESTUDENT_H

#include <QDialog>
#include "studentdb.h"

namespace Ui {
class DeleteStudent;
}

class DeleteStudent : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteStudent(QWidget *parent = nullptr);
    ~DeleteStudent();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DeleteStudent *ui;

    Student * stu;
    StudentDB * stuDB;
};

#endif // DELETESTUDENT_H
