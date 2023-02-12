#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = ServerModel::getInstance();
    connect(server, &ServerModel::incomingConnectionNotification,
            this, &MainWindow::connectionNotification);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectionNotification(qintptr socketDescriptor)
{
    ui->listWidget->insertItem(ui->listWidget->count(),QString::number(socketDescriptor));
}
