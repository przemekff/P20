#ifndef SENDINGTHREAD_H
#define SENDINGTHREAD_H
#include <sharedPins.h>
#include <QThread>
#include <QMutex>
#include <QDebug>

class SendingThread:public QThread
{
public:
    SendingThread();
    void run();

    /*
    assigning the data according to the communication protocol
    @param inputX the data to be assigned to pins[0-9]
    @param inputY the data to be assigned to pins[10-19]
    */
    void setData(bool* inputX, bool* inputY);
private:
    bool data[20];
};

#endif // SENDINGTHREAD_H
