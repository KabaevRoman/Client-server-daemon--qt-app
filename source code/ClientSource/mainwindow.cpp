#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QTextStream>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Client client;
    ui->clientStat_label->setText(client.getClientStatus());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Client client;
    ui->clientStat_label->setText(client.getClientStatus());
    QFileDialog t;
    QString filePath = t.getOpenFileName(this,"Choose file","/home");
    ui->label->setText(filePath);
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        errMsg.critical(0,"Error","File wasn't open");
    }
    else{
        QTextStream in(&file);
        QString data = in.readAll();
        QByteArray dataToSend = data.toUtf8();
        ui->textEdit->setText(dataToSend);
        client.setData(dataToSend);
        client.sendData();
    }

}
