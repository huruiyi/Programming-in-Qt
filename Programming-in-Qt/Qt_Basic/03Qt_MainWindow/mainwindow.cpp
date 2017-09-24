#include "mainwindow.h"
#include<QMenuBar>
#include<QToolBar>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QTextEdit>
#include<QMessageBox>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    this->resize(800,600);
    QMenuBar *bar=new QMenuBar(this);
    bar->setFont(QFont("微软雅黑",10,20,false));
    this->setMenuBar(bar);
    QMenu *fileMenu= bar->addMenu("文件");
    QMenu *editMenu=  bar->addMenu("编辑");

    QAction *fileNewAction=  fileMenu->addAction("新建");
    fileMenu->addSeparator();

    QAction *fileOpenAction=  fileMenu->addAction("打开");
    QAction *fileDelAction=  fileMenu->addAction("删除");
    fileNewAction->setIcon(QIcon  ("://res/qadd.ico"));
    fileOpenAction->setIcon(QIcon("://res/qopen.ico"));
    fileDelAction->setIcon(QIcon("://res/qdelete.ico"));
    fileDelAction->setCheckable(false);
     ////////////////////////////////////////////////////////////////////////////////////////

    QToolBar * toolBar=new QToolBar(this);
    //设置默认的位置
    this->addToolBar(Qt::LeftToolBarArea,toolBar);
    //设置是否允许浮动
    toolBar->setFloatable(false);
    //设置是否允许移动
    toolBar->setMovable(true);
    //设置允许显示的区域
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    QAction *barActionNew=  toolBar->addAction(QIcon  ("://res/qadd.ico"),"新建");
    //快捷键Ctrl+N 触发
    barActionNew->setShortcut(QKeySequence(tr("Ctrl+N")));

    QKeySequence(QKeySequence::Print);
    QKeySequence(tr("Ctrl+P"));
    QKeySequence(tr("Ctrl+p"));
    QKeySequence(Qt::CTRL + Qt::Key_P);

    connect(barActionNew,&QAction::triggered,this,[=](){
           qDebug() << "barActionNew is triggered";
    });
    QAction *barActionOpen=   toolBar->addAction(QIcon("://res/qopen.ico"),"打开");
    toolBar->addSeparator();
    QAction *barActionDelete=  toolBar->addAction(QIcon("://res/qdelete.ico"),"删除");
    toolBar->setFont(QFont("微软雅黑",10,20,false));




    ////////////////////////////////////////////////////////////////////////////////////////
    QStatusBar *qstatus=new QStatusBar(this);
    this->setStatusBar(qstatus);

    QLabel *leftLabel=new QLabel("Left",this);
    qstatus->addWidget(leftLabel);

    QLabel *rightLabel=new QLabel("Right",this);
    qstatus->addPermanentWidget(rightLabel);

    QDockWidget *dock=new QDockWidget("浮动",this);
    dock->setFixedHeight(100);
    //this->addDockWidget(dock);
    this->addDockWidget(Qt::TopDockWidgetArea,dock);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //核心部件 只能一个
    QTextEdit * textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}
