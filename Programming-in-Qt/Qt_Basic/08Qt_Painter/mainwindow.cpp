#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPen>
#include<QTimer>
#include<QRect>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,600);
    this->setFixedSize(600,600);
    QTimer *timer=new QTimer(this);
    timer->start(50);
    pPos=0;

    connect(timer,&QTimer::timeout,[=](){
        update();
        if(isRight)
        {
            pPos+=10;
        }
        else
        {
            pPos-=10;
        }
    });
}


void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    QPixmap pixmap(":/Image/Luffy.png");
    int width= pixmap.width();
    qDebug()<<pPos<<"  "<<this->width()<<  "图片宽度："<<width;
    if(pPos>this->width()-width)
    {
        isRight=false;
    }
    if(pPos<=0)
    {
         isRight=true;
    }

    painter.drawPixmap(pPos,10,pixmap);


//    QPen pen(QColor(255,0,0));

//    pen.setWidth(2);

//    //pen.setStyle(Qt::PenStyle::DashLine);

//    pen.setStyle(Qt::DashLine);

//    painter.setPen(pen);

//    QBrush brush(Qt::cyan);
//    brush.setColor(Qt::Dense3Pattern);
//    painter.setBrush(brush);

//    painter.drawLine(10,10,100,100);

//    painter.drawEllipse(QPoint(100,100),50,50);

//    painter.drawRect(50,50,100,100);

//    painter.drawText(QRect(10,200,150,100),"Qt绘图练习");
}
MainWindow::~MainWindow()
{
    delete ui;
}
