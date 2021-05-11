#include "server.h"
#include <QFile>
#include <syslog.h>
#include <QDir>

server::server(QObject *parent):QObject(parent)
{
    newServer = new QTcpServer(this);
    connect(newServer,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!newServer->listen(QHostAddress::LocalHost,1234))
    {
        syslog (LOG_NOTICE, "Server didn't start");
    }
    else
    {
        syslog (LOG_NOTICE, "Server started");
    }
}
void server::newConnection()
{
    QTcpSocket *socket;
    socket = newServer->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()),this,SLOT(slotReadClient()));

}
void server::slotReadClient()
{
    QTcpSocket *socket = (QTcpSocket*)sender();
    QTextStream in(socket);
    QString t =in.readAll();
    QFile file(addressOfCreatedFile);//директория куда будет помещён файл произведённый сервером, надо поменять на нужную
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<t;
    in.flush();
}
