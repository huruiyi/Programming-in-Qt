#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include <QString>


class Property
{
public:
    QString property1;
    QString property2;
};

class web_server
{
public:
    web_server();

    QString employee[];
    QString ip;
    QString port;
    Property pros;
};

#endif // WEB_SERVER_H
