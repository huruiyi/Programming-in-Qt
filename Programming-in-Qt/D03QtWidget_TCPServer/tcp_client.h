#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class Tcp_Client : public QTcpSocket
{
    //此处不可缺少
     Q_OBJECT
public:
    Tcp_Client(QObject *parent=0);

signals:
    void updateClients(QString,int);
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // TCPCLIENT_H
