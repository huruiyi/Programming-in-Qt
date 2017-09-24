#include "levelscence.h"
#include "mypushbutton.h"
#include "playerscence.h"
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QMouseEvent>
#include <QStyle>
LevelScence::LevelScence(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(320,588);
    this->setWindowTitle("翻金币");
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    QMenuBar * bar=this->menuBar();
    this->setMenuBar(bar);

    QMenu * startMen= bar->addMenu("开始");
    QAction *quitAction=startMen->addAction("退出");

    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    MyPushButton *selectButton=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    selectButton->setParent(this);
    selectButton->move(this->width()-selectButton->width(),this->height()-selectButton->height());

    connect(selectButton,&MyPushButton::clicked,[=](){

        QSound::play(":/res/BackButtonSound.wav");

        QTimer::singleShot(500,this,[=](){
            //发送自定信号
            emit this->ShowSplashScreen();
        });
    });

    this->ShowLevelShoose();
}

void LevelScence::paintEvent(QPaintEvent *)
{
    QPainter * painter=new QPainter(this);

    QPixmap pixmap;
    pixmap.load(":/res/OtherSceneBg.png");
    painter->drawPixmap(0,0,this->width(),this->height(),pixmap);

    pixmap.load(":/res/Title.png");
    pixmap= pixmap.scaled(pixmap.width()*0.6,pixmap.height()*0.6);
    painter->drawPixmap(40,30,pixmap.width(),pixmap.height(),pixmap);
}

void  LevelScence::ShowLevelShoose()
{
    //选择关卡的按钮
    for(int i = 0 ; i < 20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move( 25 + (i%4)*70 , 130 + (i/4)*70 );
        //放入数字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->move(25 + (i%4)*70 , 130 + (i/4)*70);
        label->setText(QString::number(i+1));
        //设置文本居中
        label->setAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
        //设置鼠标穿透效果  51号
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

        connect(menuBtn,&MyPushButton::clicked,[=](){
            QSound::play(":/res/TapButtonSound.wav");
            qDebug() << "您选择的是: " << i+1 << "关";
            this->playScence=new PlayerScence(i+1);
            this->playScence->move(this->x(),this->y());
            this->playScence->show();
            this->hide();
            connect(this->playScence,&PlayerScence::ShowLevelScence,[=](){
                QTimer::singleShot(500,this,[=](){
                    this->move(this->playScence->x(),this->playScence->y());
                    this->show();
                    delete this->playScence;
                    this->playScence = NULL;
                });
            });

        });

    }
}

void LevelScence::mousePressEvent(QMouseEvent *event)
{
    //QPointF wpos=  event->windowPos();
    //QPointF spos=  event->screenPos();
    //QPointF lpos=   event->localPos();

    mMoveing = true;
    QPoint globalPos=event->globalPos();
    qDebug()<<globalPos.x()<< "  "<<globalPos.y()<<"  "<<globalPos.rx()<<"  "<<globalPos.ry()<<"  "<<this->x()<<"  "<<this->y();
    mMovePosition = globalPos - pos();
    return QWidget::mousePressEvent(event);
}

void LevelScence::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
            && (event->globalPos()-mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QWidget::mouseMoveEvent(event);
}

void LevelScence::mouseReleaseEvent(QMouseEvent *event)
{
    mMoveing = false;
}
