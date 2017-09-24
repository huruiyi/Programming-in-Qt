#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = 0);

signals:
    void hungry();
    void hungry(QString foodname);
public slots:

};

#endif // MYPUSHBUTTON_H
