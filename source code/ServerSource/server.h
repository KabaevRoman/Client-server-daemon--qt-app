#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>

class server:public QObject
{
    Q_OBJECT
private:
    QTcpServer *newServer;
    QByteArray data;
public:
    explicit server(QObject *parent = 0);
    QString addressOfCreatedFile;

public slots:
    void newConnection();
    void slotReadClient();

};

#endif // SERVER_H
