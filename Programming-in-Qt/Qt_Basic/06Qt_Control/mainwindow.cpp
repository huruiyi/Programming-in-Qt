#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QListWidget>
#include<QListWidgetItem>
#include<QList>
#include<windows.h>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QListWidgetItem *item=new QListWidgetItem("锄禾日当午");

    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignCenter);

    QStringList list1;
    list1 << "锄禾日当午"<< "汗滴禾下土"<< "谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list1);

    QList<QString> list;
    list<<"第一列"<<"第二列"<<"第三列"<<"第四列";
    ui->listWidget->addItems(list);

    QIcon icon("://XPStyle/AddedIcon.ico");

    QListWidgetItem *item1=new QListWidgetItem(icon,"第五列",ui->listWidget);


    connect(ui->pbtnPaint,&QPushButton::clicked,[](){
        WinExec("mspaint",SW_NORMAL);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtnCalc_clicked()
{
      WinExec("calc",SW_NORMAL);
}

void MainWindow::on_pbtnNotePad_clicked()
{
    WinExec("notepad",SW_NORMAL);
}

void MainWindow::on_cBoxExtSatisfied_pressed()
{
    QString s=  ui->cBoxExtSatisfied->text();
    QMessageBox::information(NULL,QString("标题"),s);
}
