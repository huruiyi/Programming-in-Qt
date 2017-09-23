#include "tcp_client.h"

Tcp_Client::Tcp_Client(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}


void Tcp_Client::dataReceived()
{
    while(bytesAvailable()>0)
    {
        int length = bytesAvailable();
        char buf[1024];
        read(buf,length);

        QString msg=buf;
        emit updateClients(msg,length);
    }
}

void Tcp_Client::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
