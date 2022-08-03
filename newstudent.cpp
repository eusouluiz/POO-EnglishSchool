#include "newstudent.h"
#include "ui_newstudent.h"
#include <QMessageBox>

NewStudent::NewStudent(QWidget *parent, QList<Teacher> * teachers) :
    QDialog(parent),
    ui(new Ui::NewStudent)
{
    ui->setupUi(this);

    stuDB = new StudentDB;
    teacherList = teachers;
}

NewStudent::~NewStudent()
{
    delete ui;
    delete stuDB;
    delete teacherList;
}

void NewStudent::on_buttonBox_2_accepted()
{
    bool validation = false;
    for (int i = 0; i < teacherList->size(); i++){
        if (teacherList->at(i).getId() == ui->lineTeacherId->text().toInt()) {
            validation = true;
        }
    }
    if (validation) {
        if (ui->lineName->text().size() > 2 && ui->lineLevel->text().size() > 0){
            Student student;
            student.setName(ui->lineName->text());
            student.setLevel(ui->lineLevel->text());
            student.setTeacherId(ui->lineTeacherId->text().toInt());
            student.setGrade(0);

            stuDB->insertStudent(student);
        } else {
            QMessageBox msg;
            msg.setIcon(QMessageBox::Warning);
            msg.setText("Fields cannot be blank!");
            msg.exec();
        }
    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Invalid teacher ID!");
        msg.exec();
    }
}

void NewStudent::on_buttonBox_2_rejected()
{
    this->close();
}
