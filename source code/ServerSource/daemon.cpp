#include "daemon.h"


Daemon::Daemon(QObject *parent) : QObject(parent)
{

}

void Daemon::sigHandler(int signum)
{
    if (signum == SIGTERM)
    {
        QCoreApplication::quit();
        syslog (LOG_NOTICE, "SIGTERM exit success");
    }
    if(signum == SIGHUP)
    {
         QCoreApplication::quit();
         syslog (LOG_NOTICE, "SIGHUP exit success");
    }
}

void Daemon::skeletonDaemon()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
        exit(EXIT_SUCCESS);
    if (setsid() < 0)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
        exit(EXIT_SUCCESS);
    umask(0);
    chdir("/");
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x>=0; x--)
    {
        close (x);
    }
    signal(SIGTERM,sigHandler);
    signal(SIGHUP,sigHandler);
}
