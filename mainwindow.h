#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QMessageBox>
#include <QMainWindow>
#include "studentdb.h"
#include "teacherdb.h"
#include "login.h"
#include "newteacher.h"
#include "updateteacher.h"
#include "deleteteacher.h"
#include "newstudent.h"
#include "updatestudent.h"
#include "deletestudent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTimer();

    void on_actionNovo_cadastro_triggered();

    void on_actionAtualizar_cadastro_triggered();

    void on_actionExcluir_cadastro_triggered();

    void on_actiona_triggered();

    void on_actionNovo_aluno_triggered();

    void on_actionAtualizar_aluno_triggered();

    void on_actionExcluir_aluno_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    Teacher * currentTeacher;

    StudentDB * stuDB;
    TeacherDB * tchDB;

    Login * login;
    NewTeacher * newTeacher;
    UpdateTeacher * updateTeacher;
    DeleteTeacher * deleteTeacher;

    NewStudent * newStudent;
    UpdateStudent * updateStudent;
    DeleteStudent * deleteStudent;
};
#endif // MAINWINDOW_H
