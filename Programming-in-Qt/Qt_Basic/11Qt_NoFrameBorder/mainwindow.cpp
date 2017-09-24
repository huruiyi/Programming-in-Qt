#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDockWidget>
#include "windows.h"
#include "windowsx.h"
#include <QMouseEvent>
#include <QDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(320,588);
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
MainWindow::~MainWindow()
{
    delete ui;
}
