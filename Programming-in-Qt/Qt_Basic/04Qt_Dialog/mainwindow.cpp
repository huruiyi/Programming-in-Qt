#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDialog>
#include<QMessageBox>
#include<QFileDialog>
#include<QStandardPaths>
#include<QApplication>
#include<QDesktopServices>
#include<QPushButton>
#include<QDialogButtonBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QPushButton *  findButton = new QPushButton(tr("&Find"),this);
    findButton->resize(150,40);
    findButton->move(2,40);


    QPushButton *  moreButton = new QPushButton(tr("&More"));
    moreButton->setParent(this);
    moreButton->resize(150,40);
    moreButton->move(2,80);
    moreButton->setCheckable(true);
    moreButton->setAutoDefault(false);



    ui->setupUi(this);
    connect(ui->actionExec,&QAction::triggered,[=](){
        QDialog dlg(this);
        dlg.exec();
    });

    connect(ui->actionShow,&QAction::triggered,[=](){
        QDialog * dlg =new QDialog(this);
        dlg->show();
        dlg->setAttribute(Qt::WA_DeleteOnClose);
    });
    //设置默认选中
    ui->pushButtonGetFileName->setDefault(true);


    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    buttonBox->setParent(this);
    buttonBox->move(2,120);
//connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
//connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonGetFileName_clicked()
{
    //QDesktopWidget
    //QDesktopScreenWidget

    QString desktopPath =  QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    qDebug()<<desktopPath;
    QFileDialog dialog(this);
    QStringList filters;
    filters << "Image files (*.png *.xpm *.jpg)"
            << "Text files (*.txt)"
            << "Any files (*)";
    dialog.setNameFilters(filters);
    //dialog.setNameFilter("All C++ files (*.cpp *.cc *.C *.cxx *.c++)");
    //dialog.setNameFilter("*.cpp *.cc *.C *.cxx *.c++");
    //dialog.setNameFilter("Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");
    QString selectedFileName= dialog.getOpenFileName(this,"请选择文件",desktopPath, tr("text (*.pdf *.txt *.cpp)"));
    qDebug()<<"你选择的文件是："<<selectedFileName;
}
