#include "receivewindow.h"
#include <cmath>

ReceiveWindow::ReceiveWindow(QWidget *parent) : QWidget(parent)
{
    image = QImage(600,400,QImage::Format_RGB32);
    image.fill(qRgb(0,255,255));

}

int ReceiveWindow::deserialize(bool* data)
{
    int sum = 0;
    for (int i=0;i<=7;i++)
    {
        if(data[i]==1)
            sum += pow(2,7-i);
    }
    return sum;
}

