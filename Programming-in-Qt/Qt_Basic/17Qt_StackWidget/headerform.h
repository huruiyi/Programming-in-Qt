#ifndef HEADERFORM_H
#define HEADERFORM_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class HeaderForm;
}

class HeaderForm : public QWidget
{
    Q_OBJECT

public:
    explicit HeaderForm(QWidget *parent = 0);
    ~HeaderForm();

signals:
    void maxWindow();
    void minWindow();
    void closeWindow();

private slots:

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
private:
    Ui::HeaderForm *ui;

    QPoint m_pt;    // 存储偏移量
    QWidget* m_parent;
};

#endif // HEADERFORM_H
