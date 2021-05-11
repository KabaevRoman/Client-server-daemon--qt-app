#ifndef DAEMON_H
#define DAEMON_H
#include <QCoreApplication>
#include <QObject>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

class Daemon : public QObject
{
    Q_OBJECT
public:
    explicit Daemon(QObject *parent = nullptr);
    static void skeletonDaemon();

private:
    static void sigHandler(int);

signals:
    void done();
};

#endif // DAEMON_H
