#ifndef PLAYERSCENCE_H
#define PLAYERSCENCE_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "mycoin.h"

class PlayerScence : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayerScence(QWidget *parent = 0);

    PlayerScence(int levelIdnex);

    void paintEvent(QPaintEvent *);

    int levelIdnex;

    int gameArray[4][4];

    //保存每个Coin在二维数组中的结构
    MyCoin * coinArray[4][4];

    bool isWin;

    QLabel* winLabel;

    bool		mMoveing;
    QPoint	    mMovePosition;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void ShowLevelScence();

public slots:



};

#endif // PLAYERSCENCE_H
