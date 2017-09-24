#ifndef STAWIDGET_H
#define STAWIDGET_H

#include <QWidget>

namespace Ui {
class StaWidget;
}

class StaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StaWidget(QWidget *parent = 0);
    ~StaWidget();

private slots:
    void on_pushButton_one_clicked();

    void on_pushButton_two_clicked();

    void on_pushButton_three_clicked();

    void on_pushButton_four_clicked();

private:
    Ui::StaWidget *ui;
};

#endif // STAWIDGET_H
