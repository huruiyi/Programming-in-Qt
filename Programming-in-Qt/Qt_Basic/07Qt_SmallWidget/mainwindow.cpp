#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);     

    QTimer *timer=new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,this,[=](){
        static int num=0;
        ui->lblTimer->setText(QString::number(num++));
    });

    timerId1 = startTimer(500);
    timerId2 = startTimer(1000);

    QTimer * timer1=new QTimer(this);
    timer1->start(100);
}

void MainWindow::timerEvent(QTimerEvent *qe)
{
    if(qe->timerId()==timerId1)
    {

        qDebug()<<"1";
    }
    else if(qe->timerId()==timerId2)
    {
        qDebug()<<"2";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
