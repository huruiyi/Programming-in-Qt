#include "tcpserverwidget.h"
#include "ui_tcpserverwidget.h"

TcpServerWidget::TcpServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServerWidget)
{
    ui->setupUi(this);
}

TcpServerWidget::~TcpServerWidget()
{
    delete ui;
}

void TcpServerWidget::on_pushButton_Create_clicked()
{
    int port=ui->lineEdit_Port->text().toInt();
    server=new TcpServer(this,port);
    ui->pushButton_Create->setEnabled(false);
    connect(server,SIGNAL(updateServer(QString,int)),this,SLOT(updateServerContent(QString,int)));
}


void TcpServerWidget::updateServerContent(QString msg,int length)
{
    ui->listWidget->addItem(msg.toUtf8().left(length));
}
