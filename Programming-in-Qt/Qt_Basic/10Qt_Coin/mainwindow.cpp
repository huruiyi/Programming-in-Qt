#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QSize>
#include <QTimer>
#include <QMouseEvent>
#include "mypushbutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(320,588);
    this->setWindowTitle("翻金币");
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    connect(ui->actionExit,&QAction::triggered,[=](){this->close();});

    MyPushButton *startBtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move((this->width()-startBtn->width())/2,this->height()*0.7);

    levelScence=new LevelScence;
    connect(startBtn,&MyPushButton::clicked,[=](){
        //弹起特效
        startBtn->zoom1();
        startBtn->zoom2();
        QSound::play(":/res/TapButtonSound.wav");
        QTimer::singleShot(400,this,[=](){
            this->hide();
            levelScence->move(this->x(),this->y());
            levelScence->show();
        });
    });
    connect(levelScence,&LevelScence::ShowSplashScreen,[=](){
        levelScence->hide();
        this->move(levelScence->x(),levelScence->y());
        this->show();
    });
 }

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter * painter=new QPainter(this);

    QPixmap pixmap;
    pixmap.load(":/res/OtherSceneBg.png");
    painter->drawPixmap(0,0,this->width(),this->height(),pixmap);

    pixmap.load(":/res/Title.png");
    pixmap= pixmap.scaled(pixmap.width()*0.6,pixmap.height()*0.6);
    painter->drawPixmap(40,30,pixmap.width(),pixmap.height(),pixmap);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
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

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
        && (event->globalPos()-mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QWidget::mouseMoveEvent(event);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mMoveing = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}
