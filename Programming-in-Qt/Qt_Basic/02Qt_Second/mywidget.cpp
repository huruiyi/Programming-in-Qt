#include "mywidget.h"
#include<QLabel>
#include<QLineEdit>
#include<QImage>
#include<QBrush>
#include<QPushButton>

MyWidget::MyWidget(QWidget *parent)
: QWidget(parent)
{
    QPalette pal = palette();
    //pal.setColor(QPalette::Background, QColor( 255,255,255,1));
    //pal.setColor(QPalette::Background, QColor("Green"));
    this->setPalette(pal);
    this->setWindowOpacity(0.8);

    this->setFixedSize(600,600);
    QLabel *label1 = new QLabel(this);
    label1->resize(200,50);
    label1->move(2,2);
    label1->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label1->setText("first line\nsecond line");
    label1->setAlignment(Qt::AlignCenter | Qt::AlignLeft);

    QLineEdit *phoneEdit = new QLineEdit(this);
    phoneEdit->resize(200,50);
    phoneEdit->move(2,55);
    QLabel *phoneLabel = new QLabel("&Phone:", this);
    phoneLabel->move(2,55);
    phoneLabel->setBuddy(phoneEdit);

    QPushButton *btn=new QPushButton("QPushButton",this );
    btn->resize(200,50);
    btn->move(2,105);

    QPushButton *iButton=new QPushButton(this);
    iButton->setText("中华人民共和国军委主席");
    iButton->resize(200,50);
    iButton->move(2,155);
    iButton->show();

    QLabel  *iLabel = new QLabel;
    iLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    iLabel->setParent(iButton);

    iLabel->setWindowOpacity(0.2);
    iLabel->setText("职务：");

    //iLabel->setAttribute(Qt::WA_TranslucentBackground);



    //const QImage  image("://images/pic.png");
    //iLabel->setPixmap(QPixmap::fromImage(image));


     QPalette palette;
     palette.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));

    //palette.setBrush(QPalette::Background, QBrush(image));
    //palette.setBrush(this->rect(), QPixmap("://images/pic.png"));
    iLabel->setPalette(palette);

    this->setAutoFillBackground(true);


    //this->setAutoFillBackground(true);
    //QPalette paletteX;
    //paletteX.setColor(QPalette::Background, QColor(192,253,123));
    //paletteX.setBrush(QPalette::Background, QBrush(QPixmap("://images/Logo.ico")));
    //this->setPalette(paletteX);
}

MyWidget::~MyWidget()
{

}
