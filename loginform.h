#ifndef LOGINFORM_H
#define LOGINFORM_H

#include "clientviewmodel.h"

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_signInButton_clicked();

private:
    Ui::LoginForm *ui;
    ClientViewModel cl;
};

#endif // LOGINFORM_H
