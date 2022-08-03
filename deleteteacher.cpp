#include "deleteteacher.h"
#include "ui_deleteteacher.h"

DeleteTeacher::DeleteTeacher(QWidget *parent, Teacher * newTeacher) :
    QDialog(parent),
    ui(new Ui::DeleteTeacher)
{
    ui->setupUi(this);
    teacher = newTeacher;
}

DeleteTeacher::~DeleteTeacher()
{
    delete ui;
    delete teacher;
    delete tchDB;
}

void DeleteTeacher::on_buttonBox_accepted()
{
    if ( (ui->lineEmail->text() == teacher->getEmail()) && (ui->linePassword->text() == teacher->getPassword()) ){

        QMessageBox msg;
        msg.setIcon(QMessageBox::Question);
        msg.setText("Are you sure?");
        msg.setStandardButtons(QMessageBox::Yes|QMessageBox::Cancel);

        if (msg.exec() == QMessageBox::Yes) {
            tchDB->deleteTeacher(*teacher);
            this->accept();
        } else {
            this->reject();
        }

    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Invalid credentials!");
        msg.exec();
    }
}
