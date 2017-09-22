#include <QCoreApplication>
#include <time.h>
#include <stdio.h>
#include <QDateTime>
#include <QThread>
#include <QDebug>

void Demo_DateTime()
{
    QDateTime datetime=QDateTime::currentDateTime();
    qDebug()<<datetime.date().toString("yyyy-MM-dd")<<datetime.time().toString("hh:mm:ss");

    QDateTime datetimeS=QDateTime::currentDateTime();
    QThread::sleep(5);
    QDateTime datetimeE=QDateTime::currentDateTime();

    qDebug()<< datetimeS.secsTo(datetimeE)<< datetimeS.msecsTo(datetimeE);
}

void Demo_Clock()
{
    double time_Start = (double)clock(); //开始时间
    QThread::sleep(5);
    double timr_Finish = (double)clock(); //结束时间

    printf("operate time: %.2fms",(timr_Finish-time_Start)); //输出
}

void Demo_QtTime()
{
    QTime time;
    time.start(); //开始计时，以ms为单位
    QThread::sleep(5);
    int time_Diff = time.elapsed(); //返回从上次start()或restart()开始以来的时间差，单位ms

    //以下方法是将ms转为s
    float f = time_Diff/1000.0;
    QString tr_timeDiff = QString("%1").arg(f); //float->QString
    qDebug()<<tr_timeDiff;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Demo_QtTime();
    return a.exec();
}
