#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

QString Login::getPassword() const
{
    return password;
}

void Login::setPassword(const QString &value)
{
    password = value;
}

QString Login::getEmail() const
{
    return email;
}

void Login::setEmail(const QString &value)
{
    email = value;
}

void Login::on_Login_finished(int result)
{
    setEmail(ui->lineEmail->text());
    setPassword(ui->linePassword->text());
}
