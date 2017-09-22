#include <QCoreApplication>
#include <QDebug>

class Area
{
public:
    Area(){}

    void setR(double r)
    {
        m_r=r;
    }

    double getR()
    {
        return m_r;
    }

    double getArea()
    {
        return getR()*getR()*3.142;
    }

private:
    double m_r;
};

void Demo1()
{
    Area area;
    int i=1;
    for(i=1;i<100;++i)
    {
        area.setR(i);
        double d_area;
        d_area = area.getArea();

        qDebug()<<d_area;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
Demo1();
    return a.exec();
}
