#ifndef CLIENT_H
#define CLIENT_H
#include<QObject>
#include<QTcpSocket>
#include<QAbstractSocket>
#include<QByteArray>

class Client:public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    QByteArray data;
    QString clientStatus;
    QString sentDataStatus;

public:
    explicit Client(QObject *parent = 0);
    ~Client();
    void setData(QByteArray);
    void sendData();
    void connectToServer();
    QString getClientStatus();
    QString getSentDataStatus();

public slots:
    void bytesWritten(qint64 bytes);
    void connected();
    //void disconnected();

};

#endif // CLIENT_H
