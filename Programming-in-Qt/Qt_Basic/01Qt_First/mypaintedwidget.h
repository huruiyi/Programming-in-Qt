#ifndef MyPaintedWidget_H
#define MyPaintedWidget_H

#include <QWidget>

class MyPaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyPaintedWidget(QWidget *parent = 0);
    MyPaintedWidget();
signals:

public slots:




protected:
        void paintEvent(QPaintEvent *event);
};

#endif // MyPaintedWidget_H
