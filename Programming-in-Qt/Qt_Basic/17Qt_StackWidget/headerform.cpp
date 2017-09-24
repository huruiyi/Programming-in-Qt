#include "headerform.h"
#include "ui_headerform.h"

HeaderForm::HeaderForm(QWidget *parent) :
    //    m_parent(parent), //初始化
    QWidget(parent),
    ui(new Ui::HeaderForm)
{
    ui->setupUi(this);

    m_parent=parent;
    connect(ui->toolButton_max, &QToolButton::clicked, [=]()
    {
        emit maxWindow();
    });
    connect(ui->toolButton_min, &QToolButton::clicked, [=]()
    {
        emit minWindow();
    });
    connect(ui->toolButton_close, &QToolButton::clicked, [=]()
    {
        emit closeWindow();
    });
}

HeaderForm::~HeaderForm()
{
    delete ui;
}


void HeaderForm::mousePressEvent(QMouseEvent *event)
{
    // 只允许左键拖动窗口
    if(event->button() == Qt::LeftButton)
    {
        m_pt = event->globalPos() - m_parent->geometry().topLeft();
    }
}

void HeaderForm::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        // 鼠标的当前位置, 取屏幕坐标
        // event->globalPos();
        // 参数是窗口左上角坐标
        QPoint curPt = event->globalPos() - m_pt;
        m_parent->move(curPt);
    }
}
