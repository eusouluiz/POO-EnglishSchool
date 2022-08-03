#include "updatestudent.h"
#include "ui_updatestudent.h"

UpdateStudent::UpdateStudent(QWidget *parent, QList<Teacher> * teachers) :
    QDialog(parent),
    ui(new Ui::UpdateStudent)
{
    ui->setupUi(this);

    stuDB = new StudentDB;
    teacherList = teachers;
    ui->buttonBox->hide();
}

UpdateStudent::~UpdateStudent()
{
    delete ui;
}

void UpdateStudent::on_buttonBox_accepted()
{

}

void UpdateStudent::on_buttonBox_rejected()
{
    this->close();
}

void UpdateStudent::on_btnSearch_clicked()
{
    if (stuDB->getStudentById( ui->lineStudentId->text().toInt(), &tmpStudent) ) {
        ui->buttonBox->show();
        ui->lineName->setText(tmpStudent.getName() );
        ui->lineLevel->setText(tmpStudent.getLevel());
        ui->lineTeacherId->setText( QString::number(tmpStudent.getTeacherId()) );
    } else {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Warning);
        msg.setText("Invalid student ID!");
        msg.exec();
    }
}

void UpdateStudent::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button->text() == "Cancel"){
        this->close();
    }
    if (button->text() == "Save"){
        bool validation = false;
        for (int i = 0; i < teacherList->size(); i++){
            if (teacherList->at(i).getId() == ui->lineTeacherId->text().toInt()) {
                validation = true;
            }
        }
        if (validation) {

            if (ui->lineName->text().size() > 0 && ui->lineLevel->text().size() > 0) {
                tmpStudent.setName(ui->lineName->text());
                tmpStudent.setLevel(ui->lineLevel->text());
                tmpStudent.setTeacherId(ui->lineTeacherId->text().toInt());
                tmpStudent.setGrade(ui->lineGrade->text().toDouble());

                stuDB->updateStudent(tmpStudent);
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
}
