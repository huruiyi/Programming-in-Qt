#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(900,800);
    this->setWindowTitle("Visual Studio 2017");
    this->setWindowIcon(QIcon(":/res/visualstudio.png"));

    QTextEdit *firstdockText = new QTextEdit();
    firstdockText->setText("First QTextEdit!");

    QTextEdit *secondDockText  = new QTextEdit();
    secondDockText->setText("Second QTextEdit!");

    QTextEdit *thirdDockText = new QTextEdit();
    thirdDockText->setText("Third QTextEdit!");

    QTextEdit *dockText1 = new QTextEdit();
    dockText1->setText("Capture the button!");

    QTextEdit *dockText2 = new QTextEdit();
    dockText2->setText("Insert Dock Window!");

    QLabel* dockLabelShow =new QLabel();
    dockLabelShow->setMaximumHeight(320);
    dockLabelShow->setMaximumHeight(240);

    this->dockInsertFRight = new QDockWidget(tr("解决方案资源管理器"), this);
    this->dockInsertFRight->setWidget(firstdockText);
    this->addDockWidget(Qt::RightDockWidgetArea, dockInsertFRight);

    this->dockInsertFLeft = new QDockWidget(tr("属性管理器"), this);
    this->dockInsertFLeft->setWidget(secondDockText);
    this->addDockWidget(Qt::LeftDockWidgetArea, dockInsertFLeft);

    this->dockOverlay = new QDockWidget(tr("资源视图"), this);
    this->dockOverlay->setWidget(thirdDockText);
    this->addDockWidget(Qt::RightDockWidgetArea, dockOverlay);

    this->dockInsertButton = new QDockWidget(tr("类视图"), this);
    this->dockInsertButton->setWidget(dockText1);
    this->addDockWidget(Qt::RightDockWidgetArea, dockInsertButton);

    this->dockInsert = new QDockWidget(tr("服务器资源管理器"), this);
    this->dockInsert->setWidget(dockText2);
    this->addDockWidget(Qt::RightDockWidgetArea,dockInsert);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QTimer *t1=new QTimer(this);

    t1->start(2000);

    connect(t1,&QTimer::timeout,[=](){
        if(this->Index>6)
        {
            qDebug()<<"停止了定时器";
            t1->stop();
        }
        else
        {
            QString str=QString("Hello%1").arg(this->Index++);
            qDebug()<<str;
        }

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
