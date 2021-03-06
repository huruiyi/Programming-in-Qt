#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

   void timerEvent(QTimerEvent *);

    int timerId1;

    int timerId2;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
