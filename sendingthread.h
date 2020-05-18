#ifndef SENDINGTHREAD_H
#define SENDINGTHREAD_H
#include <sharedPins.h>
#include <QThread>

class SendingThread:public QThread
{
public:
    SendingThread();
    void run();
    void setData(bool* inputX, bool* inputY);
private:
    bool data[20];
};

#endif // SENDINGTHREAD_H
