#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mypushbutton.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
     MyPushButton *btnEmit;
     void buttonemit();
     void emitslots();
     void emitslots(QString foodName);
public slots:
    void treat();
    void treat(QString foodName);
};

#endif // MYWIDGET_H
