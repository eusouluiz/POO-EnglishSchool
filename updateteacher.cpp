#include "updateteacher.h"
#include "ui_updateteacher.h"

UpdateTeacher::UpdateTeacher(QWidget *parent, Teacher * newTeacher) :
    QDialog(parent),
    ui(new Ui::UpdateTeacher)
{
    ui->setupUi(this);
    teacher = newTeacher;

    ui->lineName->setText(teacher->getName());
    ui->lineEmail->setText(teacher->getEmail());
}

UpdateTeacher::~UpdateTeacher()
{
    delete ui;
    delete teacher;
    delete tchDB;
}

void UpdateTeacher::on_btnName_clicked()
{
    if (ui->lineName->text().size() > 0) {
        teacher->setName(ui->lineName->text());

        tchDB->updateTeacher(*teacher);
    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Fields cannot be blank!");
        msg.exec();
    }
}

void UpdateTeacher::on_btnEmail_clicked()
{
    if (ui->lineEmail->text().size() > 0) {
        teacher->setEmail(ui->lineEmail->text());

        tchDB->updateTeacher(*teacher);
    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Fields cannot be blank!");
        msg.exec();
    }
}

void UpdateTeacher::on_btnPassword_clicked()
{
    if (ui->linePassword1->text().size() > 0) {
        if (ui->linePassword1->text() != ui->linePassword2->text()){
            QMessageBox msg;
            msg.setIcon(QMessageBox::Warning);
            msg.setText("Passwords do not match!");
            msg.exec();

        } else {
            teacher->setPassword(ui->linePassword1->text());

            tchDB->updateTeacher(*teacher);
        }
    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Fields cannot be blank!");
        msg.exec();
    }
}
