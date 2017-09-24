#include "mylabel.h"
#include<QDebug>
#include<QString>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //添加鼠标追踪
    this->setMouseTracking(false);
    //setMouseTracking 设置为true的时候才能接收mousePressEvent，mouseReleaseEvent，mouseMoveEvent
}

//鼠标进入事件
void MyLabel::enterEvent(QEvent *)
{
    qDebug() << "鼠标进来了！";
}

//鼠标离开事件
void MyLabel::leaveEvent(QEvent *)
{
    qDebug() << "鼠标离开了！";
}

//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev)
{

    QString str = QString("mousePressEvent x=%1  y=%2").arg(ev->x()).arg(ev->y());
    qDebug() << str;

    //如果是左键按下，打印信息
    if(ev->button() == Qt::LeftButton)
    {

        qDebug() << str;
    }
}
//鼠标释放
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{

    QString str = QString("mouseReleaseEvent x=%1  y=%2").arg(ev->x()).arg(ev->y());
    qDebug() << str;

    if(ev->button() == Qt::LeftButton)
    {

      qDebug() << str;
    }
}
//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{

    QString str = QString("mouseMoveEvent x=%1  y=%2").arg(ev->x()).arg(ev->y());
    qDebug() << str;

    if(ev->buttons() & Qt::LeftButton)
    {

      qDebug() << str;
    }
}
