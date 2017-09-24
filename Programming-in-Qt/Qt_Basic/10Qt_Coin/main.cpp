#include "mainwindow.h"
#include <QApplication>
#include "dataconfig.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    dataConfig config;
    QVector< QVector<int> > data= config.mData[1];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            qDebug()<<data[i][j]<<"";
        }
        qDebug()<<"";
    }

    return a.exec();
}
