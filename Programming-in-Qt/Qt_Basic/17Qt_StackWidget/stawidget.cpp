#include "stawidget.h"
#include "ui_stawidget.h"

StaWidget::StaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StaWidget)
{
    ui->setupUi(this);
    // 窗口去边框
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    connect(ui->widget_header,&HeaderForm::minWindow,[=](){
        this->showMinimized();
    });

    connect(ui->widget_header,&HeaderForm::maxWindow,[=](){
        this->showMaximized();
    });

    connect(ui->widget_header,&HeaderForm::closeWindow,[=](){
        this->close();
    });
}

StaWidget::~StaWidget()
{
    delete ui;
}

void StaWidget::on_pushButton_one_clicked()
{
    ui->stackedWidget_register->setCurrentWidget(ui->page_one);
}

void StaWidget::on_pushButton_two_clicked()
{
    ui->stackedWidget_register->setCurrentWidget(ui->page_two);
}

void StaWidget::on_pushButton_three_clicked()
{
    ui->stackedWidget_register->setCurrentWidget(ui->page_three);
}

void StaWidget::on_pushButton_four_clicked()
{
    ui->stackedWidget_register->setCurrentWidget(ui->page_four);
}
