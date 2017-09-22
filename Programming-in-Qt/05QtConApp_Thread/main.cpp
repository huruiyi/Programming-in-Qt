#include <QCoreApplication>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>

QMutex mutex;

//两个线程必须声明为全局的
QThread t1;
QThread t2;

void Demo_Thread()
{
    int count=0;
    QObject::connect(&t1,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            printf("%d\t",count);
            count++;
            mutex.unlock();
        }
    });

    QObject::connect(&t2,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            QThread::msleep(10);
            printf("%d\t",count);
            count--;
            mutex.unlock();
        }
    });

    t1.start();
    t2.start();
}

void Demo_PThread()
{
    QThread *pt1=new QThread;
    QThread *pt2=new QThread;
    int count=0;
    QObject::connect(pt1,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            printf("%d\t",count);
            count++;
            mutex.unlock();
        }

    });

    QObject::connect(pt2,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            QThread::msleep(10);
            printf("%d\t",count);
            count--;
            mutex.unlock();
        }
    });

    pt1->start();
    pt2->start();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *th1=new QThread;
    QThread *th2=new QThread;
    int count=0;
    QObject::connect(th1,&QThread::started,[&]()
    {
        while (1) {
            mutex.lock();
            qDebug()<<count;
            count++;
            mutex.unlock();
        }
    });

    QObject::connect(th2,&QThread::started,[&]()
    {
        while (1) {
            mutex.lock();
            QThread::msleep(100);
            qDebug()<<count;
            count--;
            mutex.unlock();
        }
    });
    th1->start();
    th2->start();
    return a.exec();
}
