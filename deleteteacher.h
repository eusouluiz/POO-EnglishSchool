#ifndef DELETETEACHER_H
#define DELETETEACHER_H

#include <QDialog>
#include <QMessageBox>
#include "teacherdb.h"

namespace Ui {
class DeleteTeacher;
}

class DeleteTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteTeacher(QWidget *parent = nullptr, Teacher * newTeacher = nullptr);
    ~DeleteTeacher();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::DeleteTeacher *ui;

    Teacher * teacher;
    TeacherDB * tchDB;
};

#endif // DELETETEACHER_H
