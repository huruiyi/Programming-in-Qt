#ifndef LEVELSCENCE_H
#define LEVELSCENCE_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include <QSound>

#include "playerscence.h"

class LevelScence : public QMainWindow
{
    Q_OBJECT

public:

    explicit LevelScence(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);

    void   ShowLevelShoose();

    PlayerScence * playScence;

    bool		mMoveing;
    QPoint	    mMovePosition;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

    void ShowSplashScreen();

public slots:



};

#endif // LEVELSCENCE_H
