#include <QCoreApplication>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QtDebug>
#include <QJsonArray>
#include <QJsonValue>
#define J_ID        "id"
#define J_NICK      "nick"
#define J_ZHUANYE   "zhuanye"
#define J_AGE       "age"
enum {
    TAG_LOGIN,
    TAG_LOGIN_OK,
    TAG_LOGIN_FAIL,
    TAG_REGISTER,
    TAG_REGISTER_OK,
    TAG_REGISTER_FAIL,
    TAG_FIND_BACK
};

void WriteJson()
{
    QJsonObject objArr
    {
        {"property1", 1},
        {"property2", "2"}
    };
    QJsonArray jsonArr={QJsonValue(QString("员工1")),
                        QJsonValue(QString("员工2")),
                        QJsonValue(QString("员工3")),
                        QJsonValue(QString("员工4")),
                        QJsonValue(QString("员工5"))};

    QJsonObject root, subobj;
    // qjsonvalue(QJsonObject)
    subobj.insert("ip", "192.168.1.27");
    subobj.insert("port", "80");
    subobj.insert("pros",objArr);
    subobj.insert("employee",jsonArr);
    root.insert("web_server", subobj);

    // 经obj保存到磁盘
    // obj->QJsonDocument
    QJsonDocument doc(root);
    QByteArray array = doc.toJson();
    // 文件IO
    QFile file("D:\\test.json");
    file.open(QIODevice::WriteOnly);
    file.write(array);
    file.close();
}

void ReadJson()
{
    // 本地磁盘文件加载到内存
    QFile file("D:\\test.json");
    file.open(QIODevice::ReadOnly);
    QByteArray array = file.readAll();

    QJsonDocument doc = QJsonDocument::fromJson(array);
    // 判断
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        // 取值
        QJsonValue value = obj.value("web_server");
        if(value.isObject())
        {
            QJsonObject sub = value.toObject();
            QString ip = sub.value("ip").toString();
            QString port = sub.value("port").toString();
            QJsonValue jsonArr = sub.value("pros");
            if(jsonArr.isObject()){
                QJsonObject propertys=  jsonArr.toObject();
                int property1 = propertys.value("property1").toInt();
                QString property2 = propertys.value("property2").toString();
                qDebug() << "property1: "<< property1<<", property2: " << property2;
            }

            QJsonValue  objEmp= sub.value("employee");
            if(objEmp.isArray())
            {
                QJsonArray empArr = objEmp.toArray();
                int empCount = empArr.count();
                for(int i=0;i<empCount;i++)
                {
                    qDebug() << "Name: "<< empArr[i].toString() ;
                }

            }


            qDebug() << "iP: "<< ip<<", Port: " << port;
        }
    }
}

void JsonStrToOnject()
{
    QString jsonStr1= "{'web_server': {'employee': ['员工1','员工2','员工3','员工4','员工5'],'ip': '192.168.1.27','port': '80','pros': {'property1': 1,'property2': '2'}}}";






    QString s="x";
}

void Demo1()
{
    //对象转json字符串
    QMap<QString, QVariant> newData = QMap<QString, QVariant>();
    newData.insert("content", "i'm content");
    newData.insert("number", "i'm number");
    newData.insert("time", "i'm time");
    QJsonDocument doc=QJsonDocument::fromVariant(QVariant(newData));
    QByteArray jba=doc.toJson();
    QString jsonString = QString(jba);
    qDebug() << "QMap<QString, QVariant>转环后的json字符串＼n" << jsonString;
    //字符串转json对象
    QByteArray njba = jsonString.toUtf8();
    QJsonObject nobj = QJsonObject(QJsonDocument::fromJson(njba).object());
    qDebug() << "字符串转换后的对象＼n"
             << nobj.take("content").toString() << endl
             << nobj.take("number").toString() << endl
             << nobj.take("time").toString() << endl;
}

void Demo2()
{
    // 构造QJSonObject
    QJsonObject json_object;
    json_object.insert(J_ID,        "1263");
    json_object.insert(J_NICK,      "lin");
    json_object.insert(J_AGE,       20);
    json_object.insert(J_ZHUANYE,   "ruanjiangc");
    // 转换成QByteArray
    QByteArray byte_array = QJsonDocument(json_object).toJson();

    // 这时候发送byte_array
    // 另外一端对byte_array进行解析

    // QByteArray转换成QJsonObject
    QJsonObject json_object2 = QJsonDocument::fromJson(byte_array).object();
    qDebug() << json_object2.value(J_ID).toString();
    qDebug() << json_object2.value(J_NICK).toString();
    qDebug() << json_object2.value(J_AGE).toInt();
    qDebug() << json_object2.value(J_ZHUANYE).toString();
}

void Demo3()
{
    // 构造QJsonObject(从数据库中读取的时候是在循环里面构造)
    QJsonObject json_object;
    json_object.insert(J_ID,        "1263");
    json_object.insert(J_NICK,      "lin");
    json_object.insert(J_AGE,       20);
    json_object.insert(J_ZHUANYE,   "ruanjiangc");
    QJsonObject json_object2;
    json_object2.insert(J_ID,        "2345");
    json_object2.insert(J_NICK,      "jin");
    json_object2.insert(J_AGE,       5);
    json_object2.insert(J_ZHUANYE,   "ruanjiangc");
    QJsonObject json_object3;
    json_object3.insert(J_ID,        "9999");
    json_object3.insert(J_NICK,      "qiu");
    json_object3.insert(J_AGE,       21);
    json_object3.insert(J_ZHUANYE,   "ruanjiangc");
    QJsonObject json_object4;
    json_object4.insert(J_ID,        "6666");
    json_object4.insert(J_NICK,      "zhao");
    json_object4.insert(J_AGE,       19);
    json_object4.insert(J_ZHUANYE,   "ruanjiangc");
    // 构造QJsonArray
    QJsonArray json_array;
    json_array.insert(0, TAG_LOGIN);
    json_array.insert(1, json_object);
    json_array.insert(2, json_object2);
    json_array.insert(3, json_object3);
    json_array.insert(4, json_object4);
    // 转换成QByteArray
    QByteArray byte_array = QJsonDocument(json_array).toJson();

    // 这时候发送byte_array
    // 另外一端对byte_array进行解析

    // QByteArray转换成QJsonArray
    QJsonArray json_array2 = QJsonDocument::fromJson(byte_array).array();
    int tag = json_array2.at(0).toInt();
    qDebug() << "tag:" << tag;
    for(int i = 1; i < json_array2.size(); ++i) {
        QJsonObject json = json_array2.at(i).toObject();
        qDebug() << json.value(J_ID).toString();
        qDebug() << json.value(J_NICK).toString();
        qDebug() << json.value(J_AGE).toInt();
        qDebug() << json.value(J_ZHUANYE).toString();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WriteJson();
    return a.exec();
}



