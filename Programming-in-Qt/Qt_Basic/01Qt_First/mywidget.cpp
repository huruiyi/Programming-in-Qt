#include "mywidget.h"
#include<QPushButton>
#include<QDebug>
#include<QLabel>
#include<QPainter>
#include<QPicture>
#include<QGridLayout>
#include<QtCore>
#include <QImage>
#include "mypushbutton.h"
#include "mypaintedwidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //setFixedSize:设置窗口固定大小
    this->setFixedSize(1000,800);
    this->setWindowTitle("Qt-QPushButton");

    QPushButton *btnSay=new QPushButton(this);
    btnSay->show();
    btnSay->setText("你好");
    btnSay->resize(200,30);
    btnSay->move(102,2);
    //btnSay->setFlat(true);

    btnSay->setAutoFillBackground(true);

    QIcon icon("://images/Logo.ico");
    btnSay->setIcon(icon);

    QFont font("微软雅黑", 10, 10, false);
    btnSay->setFont(font);

    //QPalette pe;
    //pe.setColor(QPalette::WindowText,Qt::red);
    //btnSay->setPalette(pe);

    QPushButton *btnHello=new QPushButton;
    btnHello->show();
    btnHello->setParent(this);
    btnHello->setText("Hello");
    btnHello->resize(100,30);
    btnHello->move(2,2);

    QPushButton *btnWorld=new QPushButton("World",this);
    btnWorld->show();
    btnWorld->resize(100,30);
    btnWorld->move(2,32);

    QPushButton *btnClose=new QPushButton("Close",this);
    btnClose->show();
    //resize 设置窗体大小，可拖拽改变其大小
    btnClose->resize(100,30);
    btnClose->move(2,62);
    connect(btnClose,&QPushButton::clicked,this,&QPushButton::close);

    //创建MyPushButton的按钮
    MyPushButton * mybtn = new MyPushButton;
    mybtn->setParent(this);
    mybtn->setText("Close");
    mybtn->resize(100,30);
    mybtn->move(2,92);
    connect(mybtn,&QPushButton::clicked,this,&QPushButton::close);

    btnEmit=new MyPushButton;
    btnEmit->setParent(this);
    btnEmit->setText("emit signals");
    btnEmit->resize(100,30);
    btnEmit->move(2,122);



    QGridLayout *layout=new QGridLayout(this);

    MyPushButton  *  mbtn0=new MyPushButton;
    mbtn0->setParent(this);
    mbtn0->setText("按钮0");


    MyPushButton  *  mbtn1=new MyPushButton;
    mbtn1->setParent(this);
    mbtn1->setText("按钮1");

    MyPushButton  *  mbtn2=new MyPushButton;
    mbtn2->setParent(this);
    mbtn2->setText("按钮2");

    layout->addWidget(mbtn0,0,0);
    layout->addWidget(mbtn1,0,1);
    layout->addWidget(mbtn2,0,2);

    MyPushButton  *  mbtn3=new MyPushButton;
    mbtn3->setParent(this);
    mbtn3->setText("按钮3");

    MyPushButton  *  mbtn4=new MyPushButton;
    mbtn4->setParent(this);
    mbtn4->setText("按钮4");

    MyPushButton  *  mbtn5=new MyPushButton;
    mbtn5->setParent(this);
    mbtn5->setText("按钮5");

    layout->addWidget(mbtn3,1,0);
    layout->addWidget(mbtn4,1,1);
    layout->addWidget(mbtn5,1,2);

    this->setLayout(layout);
    this->showNormal();

    //MainWin::MainWin()
    //iButton = new QPushButton(this);
    //iLabel = new QLabel(iButton);
    //QPalette palette;
    //palette.setBrush(iLabel->backgroundRole(),QBrush(QImage(":/bmp/1257253475842.jpg")));
    //iLabel->setPalette(palette);
    //iLabel->setAutoFillBackground(true);

    //MyPaintedWidget *pw=new MyPaintedWidget(this);
    //pw->resize(800, 600);
    //pw->show();

    //无参
    void (MyPushButton::*hungrynp)()=MyPushButton::hungry;
    void (MyWidget::*treatnp)()=MyWidget::treat;
    connect(btnEmit, hungrynp, this, treatnp);
    //connect(btnEmit,SIGNAL(hungry()),this,SLOT(treat()));

    //有参
    void (MyPushButton::*hungryp)(QString)=MyPushButton::hungry;
    void (MyWidget::*treatp)(QString)=MyWidget::treat;
    connect(btnEmit, hungryp, this, treatp);
    //connect(btnEmit,SIGNAL(hungry(QString)),this,SLOT(treat(QString)));

    emitslots();
    emitslots("宫保鸡丁");
    connect(btnEmit, &QPushButton::clicked, this, &MyWidget::buttonemit);


    //////////////////////////////////////////////////////////////////////////////////////
    QLabel *label=new QLabel(this);

    label->setFixedSize(200, 30);
    label->move(102,62);
    label->setText("Qt 按钮背景图片的加载");
    //以下代码用于设置label1字体显示的大小
    label->setStyleSheet("font-size : 15px");
    label->setStyleSheet("border : 1px solid red");

    //设置label1的颜色
    QPalette pel;
    pel.setColor(QPalette::WindowText,Qt::blue);
    label->setPalette(pel);
}

void MyWidget::buttonemit()
{
    emit btnEmit->hungry();
    emit btnEmit->hungry("宫保鸡丁");
}

void MyWidget::emitslots()
{
    emit btnEmit->hungry();
}
void MyWidget::emitslots(QString foodName)
{
    emit btnEmit->hungry(foodName);
}
void MyWidget::treat()
{
    qDebug() << "请老师吃饭！";
}

void MyWidget::treat(QString foodName)
{
    qDebug() << "请老师吃:！"<<foodName.toUtf8().data();
}


MyWidget::~MyWidget()
{

}

