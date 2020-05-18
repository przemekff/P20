#include "sendingthread.h"

SendingThread::SendingThread()
{}

void SendingThread::run()
{
    for(int i=0;i<=19;i++)
    {
        sharedPins[i] = data[i];
    }
}

void SendingThread::setData(bool *inputX, bool *inputY)
{
    QMutex mutex;
    for(int i=0;i<=9;i++)
    {
        mutex.lock();
        data[i]=inputX[i];
        data[i+10]=inputY[i];
        mutex.unlock();
    }
}
