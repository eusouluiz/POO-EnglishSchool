#include "deletestudent.h"
#include "ui_deletestudent.h"

DeleteStudent::DeleteStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteStudent)
{
    ui->setupUi(this);
}

DeleteStudent::~DeleteStudent()
{
    delete ui;
}

void DeleteStudent::on_buttonBox_accepted()
{
    stuDB->deleteStudentById( ui->lineId->text().toInt() );
}

void DeleteStudent::on_buttonBox_rejected()
{
    close();
}
