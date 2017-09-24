#ifndef HSLIDER_H
#define HSLIDER_H

#include <QWidget>

namespace Ui {
class HSlider;
}

class HSlider : public QWidget
{
    Q_OBJECT

public:
    explicit HSlider(QWidget *parent = 0);
    ~HSlider();
    void setValue(int value);

private:
    Ui::HSlider *ui;
};

#endif // HSLIDER_H
