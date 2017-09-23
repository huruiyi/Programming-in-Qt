#include "tcp_server.h"

TcpServer::TcpServer(QObject *parent,int port) : QTcpServer(parent)
{
   listen(QHostAddress::LocalHost,port);
}


void TcpServer::incomingConnection(int socketDescriptor)
{
    Tcp_Client *tcpclient=new Tcp_Client(this);
    tcpclient->setSocketDescriptor(socketDescriptor);
    TcpClientList.append(tcpclient);

    connect(tcpclient,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));
    connect(tcpclient,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));
}


void TcpServer::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);
    for(int i=0;i<TcpClientList.count();i++)
    {
        QTcpSocket *item = TcpClientList.at(i);
        if(item->write(msg.toUtf8().data(),length)!=length)
        {
            continue;
        }
    }
}

void TcpServer::slotDisconnected(int descriptor)
{
    for(int i=0;i<TcpClientList.count();i++)
    {
        QTcpSocket *item = TcpClientList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            TcpClientList.removeAt(i);
            return;
        }
    }
    return;
}
