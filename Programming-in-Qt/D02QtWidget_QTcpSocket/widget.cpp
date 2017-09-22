#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    ui->lineEdit_Server_Ip->setText("127.0.0.1");
    ui->lineEdit_Server_Port->setText("8889");

    //connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(recvMsg()));
    connect(tcpSocket,&QTcpSocket::readyRead,this,this->recvMsg);

    void (QAbstractSocket:: *serror)(QAbstractSocket::SocketError)=&QTcpSocket::error;
    //connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(tcpSocket,serror,this,displayError );
}

Widget::~Widget()
{
    delete ui;
}


void Widget::displayError(QAbstractSocket::SocketError)
{
    //qWarning("this is err!");
    qDebug() << tcpSocket->errorString();
}

void Widget::on_pushButton_Connect_clicked()
{
    QString  port = ui->lineEdit_Server_Port->text();
    int  port_Int = port.toInt();
    tcpSocket->connectToHost(QHostAddress(ui->lineEdit_Server_Ip->text()), port_Int);
}

void Widget::on_pushButton_clicked()
{
    if(!tcpSocket->waitForConnected(2))
    {
        tcpSocket->disconnectFromHost();
        return;
    }
    //QTextStream out(tcpSocket);
    //不支持中文
    //out << ui->textEdit_Content_Send->toPlainText().toUtf8() <<endl;

    tcpSocket->write(ui->textEdit_Content_Send->toPlainText().toUtf8());
    tcpSocket->flush();
}

void Widget::recvMsg()
{
    //读取缓冲区数据
    QByteArray buffer = tcpSocket->readAll();
    ui->textEdit_Content_Receive->setText(buffer);
    //ui->textEdit_Content_Receive->moveCursor(QTextCursor::End);
    //tcpSocket->disconnectFromHost();
}
