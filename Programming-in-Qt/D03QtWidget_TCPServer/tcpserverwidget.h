#ifndef TCPSERVERWIDGET_H
#define TCPSERVERWIDGET_H

#include <QWidget>
#include "tcp_server.h"

namespace Ui {
class TcpServerWidget;
}

class TcpServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServerWidget(QWidget *parent = 0);
    ~TcpServerWidget();

    TcpServer * server;

private slots:
    void on_pushButton_Create_clicked();
    void updateServerContent(QString,int);

private:
    Ui::TcpServerWidget *ui;

};

#endif // TCPSERVERWIDGET_H
