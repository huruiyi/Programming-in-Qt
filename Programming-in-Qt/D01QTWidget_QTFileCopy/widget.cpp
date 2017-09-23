#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDateTime>
#include <QThread>
#include <QObject>

QThread ths[10];
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<ui->progressBar->maximum();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pbAdd_clicked()
{
    int pvalue=ui->progressBar->value();
    ui->progressBar->setValue(++pvalue);
}

void Widget::on_pbSub_clicked()
{
    int pvalue=ui->progressBar->value();
    ui->progressBar->setValue(--pvalue);
}

void CopyFile()
{
    QFile file("D:/qtfile/mysql-installer-community-5.7.19.0.msi");
    file.open(QIODevice::ReadOnly);
    file.close();

    QFileInfo fileinfo("D:/qtfile/mysql-installer-community-5.7.19.0.msi");
    int filesize=fileinfo.size();
    qDebug()<<filesize;

    int preSize=filesize/10;
    int lastSize=filesize%10;
    qDebug()<<preSize;
    qDebug()<<lastSize;

    int i=0;
    for(i=0;i<10;i++)
    {
        QObject::connect(&ths[i],&QThread::started,[&](){
            QThread::sleep(5);
            qDebug()<<i;
        });
        QObject::connect(&ths[i],&QThread::finished,[=](){
            qDebug()<<i<<"结束了-finished";
        });
    }
    int j=0;
    for(j=0;j<10;j++)
    {
        ths[j].start();
    }

    int k=0;





        for(k=0;k<10;k++)
        {
            ths[k].quit();
            ths[k].wait();
        }
    }

    void Widget::on_pbCopy_clicked()
    {
        CopyFile();

    #if 0
        QFileInfo fileinfo("D:/qtfile/mysql-installer-community-5.7.19.0.msi");
        qDebug()<<fileinfo.absoluteDir().absolutePath();
        qDebug()<<fileinfo.absoluteFilePath();
        qDebug()<<fileinfo.absolutePath();
        qDebug()<<fileinfo.baseName();
        qDebug()<<"-------------------------";
        qDebug()<<fileinfo.bundleName();
        qDebug()<<fileinfo.canonicalFilePath();
        qDebug()<<fileinfo.canonicalPath();
        qDebug()<<fileinfo.completeBaseName();
        qDebug()<<"-------------------------";
        qDebug()<<fileinfo.completeSuffix();
        qDebug()<<fileinfo.created().date().toString("yyyy-MM-dd");
        qDebug()<<fileinfo.fileName();
        qDebug()<<fileinfo.isAbsolute();
        qDebug()<<"-------------------------";
        qDebug()<<fileinfo.isBundle();
        qDebug()<<fileinfo.isDir();
        qDebug()<<fileinfo.isExecutable();
        qDebug()<<fileinfo.isFile();
        qDebug()<<"-------------------------";
        qDebug()<<fileinfo.isNativePath();
        qDebug()<<fileinfo.isRoot();
        qDebug()<<fileinfo.isSymLink();
        qDebug()<<fileinfo.isWritable();
    #endif

    }
