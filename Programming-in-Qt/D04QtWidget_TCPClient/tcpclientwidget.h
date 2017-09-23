#ifndef TCPCLIENTWIDGET_H
#define TCPCLIENTWIDGET_H

#include <QWidget>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>

namespace Ui {
class TcpClientWidget;
}

class TcpClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClientWidget(QWidget *parent = 0);
    ~TcpClientWidget();
    bool status;
    QHostAddress *serverIP;
    QTcpSocket *tcpSocket;
    QString userName;

public slots:
    //void slotEnter();
    //void slotSend();

    void slotConnected();
    void slotDisconnected();
    void dataReceived();

    void displayError(QAbstractSocket::SocketError);
private slots:
    void on_sendBtn_clicked();

    void on_enterBtn_clicked();

private:
    Ui::TcpClientWidget *ui;
};

#endif // TCPCLIENTWIDGET_H
