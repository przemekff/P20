#ifndef RECEIVETHREAD_H
#define RECEIVETHREAD_H
#include <QThread>
#include <sharedPins.h>


class receiveThread:public QThread
{

Q_OBJECT

public:
    receiveThread();
    void run();
    void assignPins(bool* target);
    int deserialize(bool* data);
    int getSX();
    int getSY();
    int getEX();
    int getEY();

signals:
    void readingFinished();
private:
    bool sCoordinateX[10];
    bool sCoordinateY[10];
    bool eCoordinateX[10];
    bool eCoordinateY[10];
};

#endif // RECEIVETHREAD_H
