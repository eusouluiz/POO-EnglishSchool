#ifndef UPDATESTUDENT_H
#define UPDATESTUDENT_H

#include <QDialog>
#include <QMessageBox>
#include <QList>
#include "studentdb.h"

namespace Ui {
class UpdateStudent;
}

class UpdateStudent : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateStudent(QWidget *parent = nullptr, QList<Teacher> * teachers = new QList<Teacher>);
    ~UpdateStudent();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_btnSearch_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::UpdateStudent *ui;

    StudentDB * stuDB;
    Student tmpStudent;
    QList<Teacher> * teacherList;
};

#endif // UPDATESTUDENT_H
