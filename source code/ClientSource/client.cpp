#include "client.h"

Client::Client(QObject *parent)
{
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));

    clientStatus = "connecting...";
    socket->connectToHost("localhost",1234);//можно заменить на адрес сервера, если он запущен не на этой машине, порт 1234(произвольный)

    if(!socket->waitForConnected(3000))
    {
        clientStatus = "Error: ";
        clientStatus+=socket->errorString();
    }
}

Client::~Client(){
    delete socket;
}

void Client::setData(QByteArray temp)
{
    data = temp;
}

void Client::bytesWritten(qint64 bytes)
{
   qDebug()<< "data written " << bytes;
}

void Client::connected()
{
    clientStatus = "Connected to server";
}

void Client::sendData()
{
    socket->write(data);
    socket->waitForBytesWritten(3000);
    socket->flush();
}

QString Client::getClientStatus()
{
    return clientStatus;
}
QString Client::getSentDataStatus()
{
    return sentDataStatus;
}
