#include "mypaintedwidget.h"
#include<QPainter>
#include<QWidget>
MyPaintedWidget::MyPaintedWidget(QWidget *parent) : QWidget(parent)
{

}


MyPaintedWidget::MyPaintedWidget()
{

}



void MyPaintedWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(80, 100, 650, 500);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50, 150, 400, 200);
}


//QPicture picture;
//QPainter painter;
//const  QColor qcol("red");
//painter.setPen(qcol);
//painter.begin(&picture);           // paint in picture
//painter.drawEllipse(10,20, 80,70); // draw an ellipse
//painter.end();                     // painting done
//picture.save("drawing.pic");


//QPainterPath path;
//path.moveTo(20, 80);
//path.lineTo(20, 30);
//path.cubicTo(80, 0, 50, 50, 80, 80);
//QPainter painter(this);
//painter.drawPath(path);


