#include "mycoin.h"
#include <QDebug>

MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
{

}


MyCoin::MyCoin(QString normalImg )
{
    //根据传进来的正常显示的图片 ，显示按钮
    QPixmap pix;
    //加载图片
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug() << normalImg << "图片加载失败";
    }
    //设置图片大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //显示图标
    this->setIcon(pix);
    //设置图片大小
    this->setIconSize(QSize(pix.width(),pix.height()));

    //创建定时器
    timer1  = new QTimer(this);
    timer2  = new QTimer(this);
    this->isAnimation=false;
    this->isWin=false;

    //监听定时器的timeout信号
    //金币翻银币 1~8
    connect(timer1,&QTimer::timeout,[=](){
         qDebug()<<"timer1:"<<this->x()<<"  "<<this->y()<<"  "<<this->isWin;
         QPixmap pix;
         QString str = QString(":/res/Coin000%1.png").arg(this->min++);
         pix.load(str);

         //设置图片大小
         this->setFixedSize(pix.width(),pix.height());
         //设置不规则图片样式
         this->setStyleSheet("QPushButton{border:0px;}");
         //显示图标
         this->setIcon(pix);
         //设置图片大小
         this->setIconSize(QSize(pix.width(),pix.height()));

        if(this->min > this->max)
        {
            this->min = 1;
            isAnimation = false;
            //停止定时器
            timer1->stop();
        }
    });

    //银币翻金币 timeout信号
    connect(timer2,&QTimer::timeout,[=](){
         qDebug()<<"timer2:"<<this->x()<<"  "<<this->y()<<"  "<<this->isWin;
         QPixmap pix;
         QString str = QString(":/res/Coin000%1.png").arg(this->max--);
         pix.load(str);

         //设置图片大小
         this->setFixedSize(pix.width(),pix.height());
         //设置不规则图片样式
         this->setStyleSheet("QPushButton{border:0px;}");
         //显示图标
         this->setIcon(pix);
         //设置图片大小
         this->setIconSize(QSize(pix.width(),pix.height()));

        if(this->max < this->min)
        {
            this->max = 8;
            isAnimation = false;
            //停止定时器
            timer2->stop();
        }
    });


}

void MyCoin::changeFlag()
{
    qDebug()<<this->x()<<"  "<<this->y()<<this->flag<<"  "<<this->isAnimation;
    if(this->flag)
    {
        //修改标志位
        this->flag = false;
        //启动定时器 金币翻银币的定时器
        timer1->start(30);
        //在做动画
        isAnimation = true;
    }
    else
    {
        this->flag = true;
        //启动定时器 银币翻金币定时器
        timer2->start(30);
        //在做动画
        isAnimation = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<"mousePressEvent:"<<this->x()<<"  "<<this->y()<<"  "<<this->flag<<this->isAnimation;;
    if(this->isAnimation||this->isWin)
    {
        return;
    }

    return QPushButton::mousePressEvent(e);
}
