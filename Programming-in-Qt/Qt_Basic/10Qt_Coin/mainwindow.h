#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "levelscence.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *);

    LevelScence * levelScence;

    bool		mMoveing;
    QPoint	    mMovePosition;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
