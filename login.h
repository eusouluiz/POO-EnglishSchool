#ifndef LOGIN_H
#define LOGIN_H

#include <QString>
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

private slots:
    void on_Login_finished(int result);

private:
    Ui::Login *ui;
    QString email;
    QString password;
};

#endif // LOGIN_H
