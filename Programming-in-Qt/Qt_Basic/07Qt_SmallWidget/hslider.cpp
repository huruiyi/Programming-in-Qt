#include "hslider.h"
#include "ui_hslider.h"

HSlider::HSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HSlider)
{
    ui->setupUi(this);


     void(QSpinBox:: *vChanged)(int) = &QSpinBox::valueChanged;


     connect(ui->hSpinBox,vChanged,ui->hHorizontalSlider,&QSlider::setValue);


     //右侧slider移动，左侧SpinBox跟着动
     connect(ui->hHorizontalSlider,&QSlider::valueChanged,ui->hSpinBox,&QSpinBox::setValue);
}

HSlider::~HSlider()
{
    delete ui;
}


void HSlider::setValue(int value)
{
    ui->hHorizontalSlider->setValue(value);
}
