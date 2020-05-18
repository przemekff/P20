#include "receivethread.h"
#include <QDebug>
#include <cmath>

receiveThread::receiveThread()
{

}

void receiveThread::run()
{
    while(1)
    {
       if(sharedPins[20]==1)
       {
           for(int i=0; i<=9;i++)
           {
               sCoordinateX[i] = sharedPins[i];
               sCoordinateY[i] = sharedPins[i+10];
           }
       }
       else
       {
           for(int i=0; i<=9;i++)
           {
               eCoordinateX[i] = sharedPins[i];
               eCoordinateY[i] = sharedPins[i+10];
           }

           emit readingFinished();
       }
    sleep(1);
    }
}

void receiveThread::assignPins(bool *target)
{
    for(int i=0;i<=9;i++)
    {
        target[i]=sharedPins[i];
    }
}

int receiveThread::getSX()
{
    return deserialize(sCoordinateX);
}

int receiveThread::getSY()
{
    return deserialize(sCoordinateY);
}

int receiveThread::getEX()
{
    return deserialize(eCoordinateX);
}

int receiveThread::getEY()
{
    return deserialize(eCoordinateY);
}

int receiveThread::deserialize(bool *data)
{
    int sum = 0;
    for (int i=0;i<=7;i++)
    {
        if(data[i]==1)
            sum += pow(2,7-i);
    }
    return sum;
}
