#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stuDB = new StudentDB;
    tchDB = new TeacherDB;

    login = new Login(this);    

    if(login->exec() == 1) {

        QString user = login->getEmail();
        QString password = login->getPassword();

        QList<Teacher> teacherList;
        teacherList = tchDB->listTeacher();

        for (int i = 0; i < teacherList.size(); i++){
            if ((user == teacherList.at(i).getEmail()) && (password == teacherList.at(i).getPassword())){
                currentTeacher = new Teacher;
                *currentTeacher = teacherList.at(i);
                break;
            }
            if( i == teacherList.size()-1 ){
                QMessageBox msg;
                msg.setIcon(QMessageBox::Warning);
                msg.setText("Invalid credentials!");
                msg.exec();
                QTimer::singleShot(10, this, SLOT(onTimer()));
            }
        }

        QList<Student> studentList;
        studentList = stuDB->listStudentsByTeacher( *currentTeacher );

        ui->twStudents->setRowCount(studentList.size());
        for(int i=0; i < studentList.size(); i++) {
            ui->twStudents->setItem(i, 0, new QTableWidgetItem( QString::number(studentList.at(i).getId()) ));
            ui->twStudents->setItem(i, 1, new QTableWidgetItem( studentList.at(i).getName() ));
            ui->twStudents->setItem(i, 2, new QTableWidgetItem( studentList.at(i).getLevel() ));
            ui->twStudents->setItem(i, 3, new QTableWidgetItem( QString::number(studentList.at(i).getGrade()) ));
        }

    } else {
        QTimer::singleShot(10, this, SLOT(onTimer()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimer()
{
    close();
}


void MainWindow::on_actionNovo_cadastro_triggered()
{
    newTeacher = new NewTeacher;
    newTeacher->exec();
}

void MainWindow::on_actionAtualizar_cadastro_triggered()
{
    updateTeacher = new UpdateTeacher(this, currentTeacher);
    updateTeacher->exec();
}

void MainWindow::on_actionExcluir_cadastro_triggered()
{
    deleteTeacher = new DeleteTeacher(this, currentTeacher);
    deleteTeacher->exec();
    if (deleteTeacher->result()){
        close();
    }

}

void MainWindow::on_actiona_triggered()
{
    QTimer::singleShot(10, this, SLOT(onTimer()));
}

void MainWindow::on_actionNovo_aluno_triggered()
{
    QList<Teacher> teachers;
    teachers = tchDB->listTeacher();
    newStudent = new NewStudent(this, &teachers);
    newStudent->exec();

}

void MainWindow::on_actionAtualizar_aluno_triggered()
{
    QList<Teacher> teachers;
    teachers = tchDB->listTeacher();
    updateStudent = new UpdateStudent(this, &teachers);
    updateStudent->exec();
}

void MainWindow::on_actionExcluir_aluno_triggered()
{
    deleteStudent = new DeleteStudent;
    deleteStudent->exec();
}

void MainWindow::on_pushButton_clicked()
{
    QList<Student> studentList;
    studentList = stuDB->listStudentsByTeacher( *currentTeacher );

    ui->twStudents->setRowCount(studentList.size());
    for(int i=0; i < studentList.size(); i++) {
        ui->twStudents->setItem(i, 0, new QTableWidgetItem( QString::number(studentList.at(i).getId()) ));
        ui->twStudents->setItem(i, 1, new QTableWidgetItem( studentList.at(i).getName() ));
        ui->twStudents->setItem(i, 2, new QTableWidgetItem( studentList.at(i).getLevel() ));
        ui->twStudents->setItem(i, 3, new QTableWidgetItem( QString::number(studentList.at(i).getGrade()) ));
    }
}
