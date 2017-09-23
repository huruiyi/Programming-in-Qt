#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include "tcp_client.h"
#include <QList>
class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    TcpServer(QObject *parent=0,int port=0);
    QList<Tcp_Client*> TcpClientList;
signals:
    void updateServer(QString,int);

public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
    //重写连接到来的处理函数
    void incomingConnection(int socketDescriptor);
};

#endif // TCPSERVER_H
