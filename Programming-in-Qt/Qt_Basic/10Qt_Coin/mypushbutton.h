#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPixmap>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QDebug>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);

    QString normalImg;
    QString selectedImg;
    MyPushButton(QString normalImg,QString selectedImg="");

    void zoom1(); //向下跳跃
    void zoom2(); //向上跳跃

    void  mousePressEvent(QMouseEvent *);

    void mouseReleaseEvent(QMouseEvent *);
signals:


public slots:
};

#endif // MYPUSHBUTTON_H
