#ifndef NEWTEACHER_H
#define NEWTEACHER_H

#include "teacherdb.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class NewTeacher;
}

class NewTeacher : public QDialog
{
    Q_OBJECT

public:
    explicit NewTeacher(QWidget *parent = nullptr);
    ~NewTeacher();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::NewTeacher *ui;

    TeacherDB * tchDB;
};

#endif // NEWTEACHER_H
