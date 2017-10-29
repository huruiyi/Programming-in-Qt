#include <QCoreApplication>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMutex>



QMutex mutex;

//两个线程必须声明为全局的
QThread t1;
QThread t2;

void Demo_Thread()
{
    int count=0;
    QObject::connect(&t1,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            printf("%d\t",count);
            count++;
            mutex.unlock();
        }
    });

    QObject::connect(&t2,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            QThread::msleep(10);
            printf("%d\t",count);
            count--;
            mutex.unlock();
        }
    });

    t1.start();
    t2.start();
}

void Demo_PThread()
{
    QThread *pt1=new QThread;
    QThread *pt2=new QThread;
    int count=0;
    QObject::connect(pt1,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            printf("%d\t",count);
            count++;
            mutex.unlock();
        }

    });

    QObject::connect(pt2,&QThread::started,[&] ()
    {
        while (1) {
            mutex.lock();
            QThread::msleep(10);
            printf("%d\t",count);
            count--;
            mutex.unlock();
        }
    });

    pt1->start();
    pt2->start();
}


class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork(const QString &parameter)
    {
        QString result;
        /* ... here is the expensive or blocking operation ... */
        emit resultReady(result);
    }

signals:
    void resultReady(const QString &result);
};

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller() {
        Worker *worker = new Worker;
        worker->moveToThread(&workerThread);
        connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
        connect(this, &Controller::operate, worker, &Worker::doWork);
        connect(worker, &Worker::resultReady, this, &Controller::handleResults);
        workerThread.start();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(const QString &);
signals:
    void operate(const QString &);
};

class WorkerThread : public QThread
{
    Q_OBJECT
    void run() override {
        QString result;
        /* ... here is the expensive or blocking operation ... */
        emit resultReady(result);
    }
signals:
    void resultReady(const QString &s);
};

class Counter
  {
  public:
      Counter() { n = 0; }

      void increment()
      {
          QMutexLocker locker(&mutex);
          ++n;
      }
      void decrement()
      {
          QMutexLocker locker(&mutex);
          --n;
      }
      int value() const
      {
          QMutexLocker locker(&mutex);
          return n;
      }

  private:
      mutable QMutex mutex;
      int n;
  };


void MyObject::startWorkInAThread()
{
    WorkerThread *workerThread = new WorkerThread(this);
    connect(workerThread, &WorkerThread::resultReady, this, &MyObject::handleResults);
    connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
    workerThread->start();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *th1=new QThread;
    QThread *th2=new QThread;
    int count=0;
    QObject::connect(th1,&QThread::started,[&]()
    {
        while (1) {
            mutex.lock();
            qDebug()<<count;
            count++;
            mutex.unlock();
        }
    });

    QObject::connect(th2,&QThread::started,[&]()
    {
        while (1) {
            mutex.lock();
            QThread::msleep(100);
            qDebug()<<count;
            count--;
            mutex.unlock();
        }
    });
    th1->start();
    th2->start();
    return a.exec();
}
