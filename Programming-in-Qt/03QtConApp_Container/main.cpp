#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

/*
    //动态数组,基于qlist
    QVector<int> vectorList;
    //哈希表
    QSet<int> setList;
    //
    QList<int> listList;
*/
void Demo_Limit()
{
    qDebug()<<sizeof(long long);
    qDebug()<<sizeof(int);
    qDebug()<<INT_MAX<<INT_MIN;
    qDebug()<<LLONG_MAX<<LLONG_MIN;
    qDebug()<<LONG_MAX<<LONG_MIN;
}


void Demo_QList()
{
    QDateTime datetimeS=QDateTime::currentDateTime();
    QList<int> list;
    int i=0;
    for(i=0;i<10000;i++)
    {
        list<<i;
    }

    for(i=0;i<10000;i++)
    {
        list<<i;
    }

    for(QList<int>::iterator ite=list.begin();ite!=list.end();ite++)
    {
        printf("%d\t",*ite);
    }

    qDebug()<<"QList<int> list:Size= "<<list.count();
    QDateTime datetimeE=QDateTime::currentDateTime();
    qDebug()<< datetimeS.secsTo(datetimeE)<< datetimeS.msecsTo(datetimeE);
}

void Demo_QVector()
{
    QDateTime datetimeS=QDateTime::currentDateTime();
    QVector<int> list;
    int i=0;
    for(i=0;i<10000;i++)
    {
        list<<i;
    }
    for(i=0;i<10000;i++)
    {
        list<<i;
    }

    for(QVector<int>::iterator ite=list.begin();ite!=list.end();ite++)
    {
        printf("%d\t",*ite);
    }

    qDebug()<<"QVector<int> list:Size= "<<list.count();
    QDateTime datetimeE=QDateTime::currentDateTime();
    qDebug()<< datetimeS.secsTo(datetimeE)<< datetimeS.msecsTo(datetimeE);
}

void Demo_QSet()
{
    QDateTime datetimeS=QDateTime::currentDateTime();
    QSet<int> list;
    int i=0;
    for(i=0;i<10000;i++)
    {
        list<<i;
    }
    for(i=0;i<10000;i++)
    {
        list<<i;
    }

    for(QSet<int>::iterator ite=list.begin();ite!=list.end();ite++)
    {
        printf("%d\t",*ite);
    }

    qDebug()<<"QSet<int> list:Size= "<<list.count();
    QDateTime datetimeE=QDateTime::currentDateTime();
    qDebug()<< datetimeS.secsTo(datetimeE)<< datetimeS.msecsTo(datetimeE);
}

int main(int argc, char *argv[])
{
    //QList<int> list:Size=  20000
    //4 4723

    //QVector<int> list:Size=  20000
    //4 4483

    //QSet<int> list:Size=  10000
    //2 2630

    QCoreApplication a(argc, argv);

    //Demo_QList();
    //getchar();
    //Demo_QVector();
    //getchar();
    //Demo_QSet();
    //getchar();


    return a.exec();
}
