#include "widget.h"
#include "ui_widget.h"
#include <QPicture>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QFile file(":/res/visualstudio.png");
    //if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    //    return;

    //QByteArray qBYte= file.readAll();
    //qDebug()<<qBYte;

    //QImage iamge;
    //bool imageLoad= iamge.loadFromData(qBYte,"");

    //qDebug()<<"Load:"<<imageLoad;


    QByteArray pData;
    QFile *file=new QFile(":/res/visualstudio.png");

    file->open(QIODevice::ReadOnly);
    pData=file->readAll();

    QImage image;
    bool result= image.loadFromData(pData);

    qDebug()<<"Load:"<<result;
}

Widget::~Widget()
{
    delete ui;
}
