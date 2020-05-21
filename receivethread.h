#ifndef RECEIVETHREAD_H
#define RECEIVETHREAD_H
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <cmath>
#include <unistd.h>
#include <sharedPins.h>


class receiveThread:public QThread
{

Q_OBJECT

public:
    receiveThread();
    void run();

    /*
     collects the data from shared pins and saves it to the target
     @param target The array the data is saved to
    */
    void assignPins(bool* target);

    /*
     converting a binary number saved as array into int
     @param data The array to be converted
     @return int The decimal number
    */
    int deserialize(bool* data);

    //accesors for private attributes
    int getSX();
    int getSY();
    int getEX();
    int getEY();

signals:

    //signalling the thread has finished reading data from sharedPins
    void readingFinished();

    void clearBtnSignal();

private:
    bool sCoordinateX[10];
    bool sCoordinateY[10];
    bool eCoordinateX[10];
    bool eCoordinateY[10];
};

#endif // RECEIVETHREAD_H
