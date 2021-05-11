#include <QCoreApplication>
#include "server.h"
#include <iostream>
#include <QFile>
#include <QDir>
#include "daemon.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QDir currentpath;
    QString currentPath = currentpath.currentPath();
    currentPath+="/newfile.txt";
    Daemon d;
    d.skeletonDaemon();
    server t;
    t.addressOfCreatedFile = currentPath;//можно задать свой путь к создаваемому файлу,
    //по умолчанию файл появляется в директории откуда была запущена программа
    qDebug()<<currentPath;

    return a.exec();
}
