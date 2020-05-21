#include "sendingthread.h"

SendingThread::SendingThread()
{}

void SendingThread::run()
{
    QMutex mutex;
    for(int i=0;i<=19;i++)
    {
        mutex.lock();
        sharedPins[i] = data[i];
        mutex.unlock();
    }
}

void SendingThread::setData(bool *inputX, bool *inputY)
{

    for(int i=0;i<=9;i++)
    {   
        data[i]=inputX[i];
        data[i+10]=inputY[i];  
    }
}
