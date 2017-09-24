#include "playerscence.h"
#include "mypushbutton.h"
#include <QApplication>
#include <QTimer>
#include <QLabel>
#include <QPainter>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFont>
#include <QVector>
#include <QDebug>
#include <QPropertyAnimation>
#include <QSound>
#include <QMouseEvent>
#include "mycoin.h"
#include "dataconfig.h"

PlayerScence::PlayerScence(QWidget *parent) : QMainWindow(parent)
{

}

void PlayerScence::paintEvent(QPaintEvent *)
{
    QPainter * painter=new QPainter(this);

    QPixmap pixmap;
    pixmap.load(":/res/OtherSceneBg.png");
    painter->drawPixmap(0,0,this->width(),this->height(),pixmap);

    pixmap.load(":/res/Title.png");
    pixmap= pixmap.scaled(pixmap.width()*0.6,pixmap.height()*0.6);
    painter->drawPixmap(40,30,pixmap.width(),pixmap.height(),pixmap);




}

PlayerScence::PlayerScence(int levelIdnex)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->levelIdnex=levelIdnex;

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

    MyPushButton *backButton=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backButton->setParent(this);
    backButton->move(this->width()-backButton->width(),this->height()-backButton->height());
    connect(backButton,&MyPushButton::clicked,[=](){
        QSound::play(":/res/BackButtonSound.wav");
        emit this->ShowLevelScence();
    });

    QLabel *label=new QLabel(this);
    QString levelInfo=QString("Level %1").arg(this->levelIdnex);
    QPalette palette;

    palette.setColor(QPalette::WindowText,QColor(245,232,191));
    label->setPalette(palette);
    label->setFont(QFont("微软雅黑",14,3,false));
    label->setText(levelInfo);
    //label->move(20,this->height()-label->height());
    label->setGeometry(QRect(30, this->height() - 50,120, 50));

    dataConfig config;
    QVector<QVector<int>> data= config.mData[this->levelIdnex];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j]=data[i][j];
        }
    }
    this->isWin = true;

    winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 ,  -tmpPix.height());

    //创建金币背景图标
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4;j++)
        {
            //创建背景图  利用QLabel
            QLabel *bg = new QLabel;
            bg->setGeometry(0,0,50,50); //设置大小 并且放到左上角
            bg->setParent(this);
            bg->setPixmap(QPixmap(":/res/BoardNode.png"));
            bg->move(57 + i*50,200+j*50); //背景位置设置

            //创建金币按钮
            //初始化界面
            QString str;
            if(this->gameArray[i][j] == 1)
            {
                str = ":/res/Coin0001.png";
            }
            else
            {
                str = ":/res/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(59 + i*50,204+j*50);
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];

            coinArray[i][j] = coin;
            //监听金币点击的信号
            connect(coin,&MyCoin::clicked,[=](){
                QSound::play(":/res/ConFlipSound.wav");
                qDebug()<<"监听金币点击的信号:"<<this->x()<<"  "<<this->y()<<"  "<<this->isWin;
                coin->changeFlag();
                //二维数组也跟着同步修改数据
                gameArray[i][j] = gameArray[i][j]== 1 ? 0 : 1;

                for(int i = 0 ; i< 4;i++)
                {
                    for(int j = 0 ; j< 4;j++)
                    {
                        coinArray[i][j]->isWin = true;
                    }
                }

                //周围金币延时翻转
                QTimer::singleShot(300,this,[=](){
                    QSound::play(":/res/ConFlipSound.wav");
                    qDebug()<<"周围金币延时翻转:"<<this->x()<<"  "<<this->y()<<"  "<<this->isWin;
                    if(coin->posX + 1 <= 3) //0 1 2 3 是可以翻转的下标
                    {
                        //右侧翻转条件
                        coinArray[coin->posX+1][coin->posY]->changeFlag();
                        gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY]== 1 ? 0 : 1;
                    }
                    if(coin->posX - 1 >= 0)
                    {
                        //左侧翻转条件
                        coinArray[coin->posX-1][coin->posY]->changeFlag();
                        gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY]== 1 ? 0 : 1;
                    }
                    if(coin->posY + 1 <=3)
                    {
                        //下侧翻转条件
                        coinArray[coin->posX][coin->posY+1]->changeFlag();
                        gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX][coin->posY+1]== 1 ? 0 : 1;
                    }
                    if(coin->posY -1 >=0)
                    {
                        //上侧翻转条件
                        coinArray[coin->posX][coin->posY-1]->changeFlag();
                        gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX][coin->posY-1]== 1 ? 0 : 1;
                    }
                    this->isWin=true;
                    for(int ix=0;ix <4;ix++)
                    {
                        for(int jy=0;jy<4;jy++)
                        {
                            if(coinArray[ix][jy]->flag==false)
                            {
                                this->isWin=false;
                                break;
                            }
                        }
                    }
                    if(this->isWin)
                    {
                        QSound::play(":/res/LevelWinSound.wav");
                        for(int ix=0;ix <4;ix++)
                        {
                            for(int jy=0;jy<4;jy++)
                            {
                                coinArray[ix][jy]->isWin=true;
                            }
                        }
                        QPropertyAnimation * animation1 =  new QPropertyAnimation(winLabel,"geometry");
                        animation1->setDuration(1000);
                        animation1->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        animation1->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        animation1->setEasingCurve(QEasingCurve::OutBounce);
                        animation1->start();
                    }
                    else
                    {
                        for(int ix=0;ix <4;ix++)
                        {
                            for(int jy=0;jy<4;jy++)
                            {
                                coinArray[ix][jy]->isWin=false;
                            }
                        }
                    }
                });

            });
        }
    }
}


void PlayerScence::mousePressEvent(QMouseEvent *event)
{
    QPointF wpos=  event->windowPos();
    QPointF spos=  event->screenPos();
    QPointF lpos=   event->localPos();

    mMoveing = true;
    QPoint globalPos=event->globalPos();
    qDebug()<<globalPos.x()<< "  "<<globalPos.y()<<"  "<<globalPos.rx()<<"  "<<globalPos.ry()<<"  "<<this->x()<<"  "<<this->y();
    mMovePosition = globalPos - pos();
    return QWidget::mousePressEvent(event);
}

void PlayerScence::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
            && (event->globalPos()-mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QWidget::mouseMoveEvent(event);
}

void PlayerScence::mouseReleaseEvent(QMouseEvent *event)
{
    mMoveing = false;
}

