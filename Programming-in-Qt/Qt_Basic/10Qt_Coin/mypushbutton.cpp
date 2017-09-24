#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

MyPushButton::MyPushButton(QString normalImg,QString selectedImg)
{
    this->normalImg=normalImg;
    this->selectedImg=selectedImg;

    QPixmap pixmap;
    bool result=pixmap.load(normalImg);
    if(result)
    {
        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
}

void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");

    //设置时间间隔
    animation1->setDuration(200);

    qDebug()<<"zoom1s:"<<this->y()<<"  "<<this->y()+10;
    //创建起始位置 和结束位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置弹起效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation1->start();

    qDebug()<<"zoom1e"<<this->y()<<"  "<<this->y()+10;

}//向下跳跃
void MyPushButton::zoom2()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");

    //设置时间间隔
    animation1->setDuration(200);

    qDebug()<<"zoom2s:"<<this->y()<<"  "<<this->y()+10;

    //创建起始位置 和结束位置
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置弹起效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation1->start();

     qDebug()<<"zoom2e"<<this->y()<<"  "<<this->y()+10;
}//向上跳跃


void  MyPushButton::mousePressEvent(QMouseEvent * e)
{
    QPixmap pixmap;
    bool result=pixmap.load(this->normalImg);
    if(result)
    {
        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }

    return  QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent * e)
{
    QPixmap pixmap;
    bool result=pixmap.load(this->selectedImg);
    if(result)
    {
        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
   return QPushButton::mouseReleaseEvent(e);
}
