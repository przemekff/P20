#include "receivethread.h"


receiveThread::receiveThread()
{
  //setting initial values to zero to avoid drawing line before the data is sent
  for (int i=0; i<=9; i++)
  {
      sCoordinateX[i]=0;
      sCoordinateY[i]=0;
      eCoordinateX[i]=0;
      eCoordinateY[i]=0;
  }
}

void receiveThread::run()
{
    QMutex mutex;
    while(1)
    {
       if(sharedPins[10]==1)
           emit clearBtnSignal();
       else
       {
        if(sharedPins[20]==1)//case where the starting point is being sent
        {

           for(int i=0; i<=9;i++)
           {
               qDebug()<<sharedPins[i];
               mutex.lock();
               sCoordinateX[i] = sharedPins[i];
               sCoordinateY[i] = sharedPins[i+10];
               mutex.unlock();
           }
        }
        else//case where the ending point is being sent
        {

           for(int i=0; i<=9;i++)
           {
               mutex.lock();
               eCoordinateX[i] = sharedPins[i];
               eCoordinateY[i] = sharedPins[i+10];
               mutex.unlock();
           }

           emit readingFinished();
        }
       }
     usleep(10);
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
    for (int i=0;i<=9;i++)
    {
        if(data[i]==1)
            sum += pow(2,9-i);
    }
    return sum;
}
