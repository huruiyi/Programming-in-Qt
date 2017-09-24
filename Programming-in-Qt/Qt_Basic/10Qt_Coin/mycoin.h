#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = 0);

    MyCoin(QString normalImg );

    int posX;
    int posY;
    bool flag;

    //修改标志
    void changeFlag();
    QTimer * timer1;
    QTimer * timer2;

    int max = 8;
    int min = 1;

    bool isAnimation;
    bool isWin;

    void mousePressEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYCOIN_H
