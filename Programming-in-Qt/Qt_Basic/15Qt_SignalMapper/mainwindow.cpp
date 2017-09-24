#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSignalMapper * mapper=new QSignalMapper();
    QList<QPushButton *> list=
    {
        ui->pushButton_1,
        ui->pushButton_2,
        ui->pushButton_3,
        ui->pushButton_4,
        ui->pushButton_5,
        ui->pushButton_6
    };

    for(int i=0;i<list.size();++i)
    {
        mapper->setMapping(list.at(i),list.at(i)->text());
        connect(list.at(i), SIGNAL(clicked()), mapper, SLOT(map()));
    }
    connect(mapper, SIGNAL(mapped(QString)), this, SLOT(myslot(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myslot(QString text)
{
    QString str = QString("hello, world --- %1").arg(text);
    ui->textEdit->setText(str);
}
