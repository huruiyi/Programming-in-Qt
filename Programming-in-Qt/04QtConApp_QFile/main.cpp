#include <QCoreApplication>
#include <QFile>

void Demo_printError(const char* msg)
{
    QFile file;
    file.open(stderr, QIODevice::WriteOnly);
    file.write(msg, qstrlen(msg));        // write to stderr
    file.close();
}

void Demo_ReadFromFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly );
    char buf[2048]={0};
    while (!file.atEnd())
    {
#if 0 /*一行一行的读取*/
        memset(buf,0,sizeof(buf));
        file.readLine(buf,sizeof(buf));
        printf("%s",buf);
#endif

#if 0 /*一次读取所有内容*/
        QByteArray byteArray = file.readAll();
        char *ch = byteArray.data();
        printf("%s",ch);
#endif

#if 1 /*一段一段的读取*/
        memset(buf,0,sizeof(buf));
        file.read(buf,sizeof(buf));
        printf("%s",buf);
#endif

    }
    file.close();
}
void Demo_WriteToFile(QString filename,char * data)
{
    QFile file(filename);
    file.open(QIODevice::WriteOnly );
    file.write(data);
    file.flush();
    file.close();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Demo_printError("shut down");
    Demo_WriteToFile("a.txt","abcdefghijkl\r\n123456789\r\nABCDEFGHIJKL\r\n");
    Demo_ReadFromFile("a.txt");

    return a.exec();
}

/*

  QProcess gzip;
  gzip.start("gzip", QStringList() << "-c");
  if (!gzip.waitForStarted())
      return false;

  gzip.write("uncompressed data");

  QByteArray compressed;
  while (gzip.waitForReadyRead())
      compressed += gzip.readAll();
*/
