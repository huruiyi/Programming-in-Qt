#include "tcpclientwidget.h"
#include "ui_tcpclientwidget.h"

TcpClientWidget::TcpClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClientWidget)
{
    ui->setupUi(this);

    serverIP =new QHostAddress();
    ui->sendBtn->setEnabled(false);
}

TcpClientWidget::~TcpClientWidget()
{
    delete ui;
}

void TcpClientWidget::on_sendBtn_clicked()
{
    if(ui->sendLineEdit->text()=="")
    {
        return ;
    }

    QString msg=userName+":"+ui->sendLineEdit->text();

    tcpSocket->write(msg.toUtf8());
    ui->sendLineEdit->clear();
}

void TcpClientWidget::on_enterBtn_clicked()
{
    if(!status)
    {
        QString ip = ui->serverIPLineEdit->text();
        if(!serverIP->setAddress(ip))
        {
            QMessageBox::information(this,tr("error"),tr("server ip address error!"));
            return;
        }

        if(ui->userNameLineEdit->text()=="")
        {
            QMessageBox::information(this,tr("error"),tr("User name error!"));
            return;
        }

        userName=ui->userNameLineEdit->text();

        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
        connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

        void (QAbstractSocket:: *serror)(QAbstractSocket::SocketError)=&QTcpSocket::error;
        //connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
        connect(tcpSocket,serror,this,displayError );

        int port=ui->portLineEdit->text().toInt();
        tcpSocket->connectToHost(*serverIP,port);

        status=true;
    }
    else
    {
        QString msg=userName+tr(":Leave Chat Room");
        qint64  length=  tcpSocket->write(msg.toUtf8());
        qDebug()<<"actually write:"<<length;
        if(length!=msg.toUtf8().length())
        {
            return;
        }

        tcpSocket->disconnectFromHost();

        status=false;
    }
}



void TcpClientWidget::slotConnected()
{
    ui->sendBtn->setEnabled(true);
    ui->enterBtn->setText(tr("离开"));


    QString msg=userName+tr(":Enter Chat Room");
    qint64 length=tcpSocket->write(msg.toUtf8() );
    if( length !=msg.toUtf8().length())
    {
        return;
    }
}

void TcpClientWidget::slotDisconnected()
{
    ui->sendBtn->setEnabled(false);
    ui->enterBtn->setText(tr("进入聊天室"));
}

void TcpClientWidget::dataReceived()
{
    while(tcpSocket->bytesAvailable()>0)
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());

        tcpSocket->read(datagram.data(),datagram.size());

        QString msg=datagram.data();
        ui->contentListWidget->addItem(msg.left(datagram.size()));
    }
}

void TcpClientWidget::displayError(QAbstractSocket::SocketError)
{
    //qWarning("this is err!");
    qDebug() << tcpSocket->errorString();
}
