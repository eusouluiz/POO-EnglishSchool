#include "newteacher.h"
#include "ui_newteacher.h"

NewTeacher::NewTeacher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTeacher)
{
    ui->setupUi(this);

    tchDB = new TeacherDB;
}

NewTeacher::~NewTeacher()
{
    delete ui;
    delete tchDB;
}

void NewTeacher::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text() == "Close"){
        this->close();
    }
    if (button->text() == "Save"){
        if(ui->lineName->text().size() > 2 && ui->lineEmail->text().size() > 2 && ui->linePassword1->text().size() > 0){
            if (ui->linePassword1->text() != ui->linePassword2->text()){
                QMessageBox msg;
                msg.setIcon(QMessageBox::Warning);
                msg.setText("Passwords do not match!");
                msg.exec();

            } else {
                Teacher teacher;
                teacher.setName(ui->lineName->text());
                teacher.setEmail(ui->lineEmail->text());
                teacher.setName(ui->lineName->text());
                teacher.setPassword(ui->linePassword1->text());

                tchDB->insertTeacher(teacher);
            }
        } else {
            QMessageBox msg;
            msg.setIcon(QMessageBox::Warning);
            msg.setText("Fields cannot be blank!");
            msg.exec();
        }
    }
}
