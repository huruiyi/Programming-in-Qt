#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QHostAddress>
#include <QTextStream>
#include <QTextEdit>
#include <QByteArray>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void recvMsg();
    void displayError(QAbstractSocket::SocketError);
    void on_pushButton_Connect_clicked();
    void on_pushButton_clicked();
private:
    QTcpSocket *tcpSocket;
    Ui::Widget *ui;
};

#endif // WIDGET_H
