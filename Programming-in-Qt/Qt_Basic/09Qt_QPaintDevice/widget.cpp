#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /////////////////////////QPixmap///////////////////////////////
    //QPixmap pix(300,300);
    //pix.fill(Qt::white);

    //QPainter painter(&pix);
    //painter.setPen(QPen(Qt::blue));
    //painter.drawEllipse(QPoint(150,150),100,100);
    //painter.setFont(QFont("微软雅黑",20,3,false));
    //painter.setPen(QPen(Qt::red));
    //painter.drawText(140,160,"鑫");
    //pix.save("pix.png");
    /////////////////////////QPixmap///////////////////////////////


    //QImage 对像素级访问做了优化
    QImage img(300,300,QImage::Format_RGB888);
    img.fill(Qt::white);
    QPainter painter2(&img);
    painter2.setFont(QFont("微软雅黑",20,3,false));
    painter2.setPen(QPen(Qt::red));
    painter2.drawText(140,160,"鑫");
    painter2.setPen(QPen(Qt::blue));
    painter2.drawEllipse(QPoint(150,150),100,100);
    //保存
    img.save("img.png");


    //QBitmap


}

//绘图事件
void Widget::paintEvent(QPaintEvent *)
{

}

Widget::~Widget()
{
    delete ui;
}
