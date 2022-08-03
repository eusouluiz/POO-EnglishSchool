#ifndef UPDATETEACHER_H
#define UPDATETEACHER_H

#include <QDialog>
#include <QMessageBox>
#include "teacherdb.h"

namespace Ui {
class UpdateTeacher;
}

class UpdateTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateTeacher(QWidget *parent = nullptr, Teacher * newTeacher = nullptr);
    ~UpdateTeacher();


private slots:
    void on_btnName_clicked();

    void on_btnEmail_clicked();

    void on_btnPassword_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::UpdateTeacher *ui;

    Teacher * teacher;
    TeacherDB * tchDB;
};

#endif // UPDATETEACHER_H
