#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "serverModel.h"

#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void connectionNotification(qintptr socketDescriptor);

private:
    Ui::MainWindow *ui;
    ServerModel *server;
};

#endif // MAINWINDOW_H
