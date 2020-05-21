#include "receivewindow.h"


ReceiveWindow::ReceiveWindow(QWidget *parent) : QWidget(parent)
{
    image = QImage(600,400,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    rThread.start();
    connect(&rThread, SIGNAL(readingFinished()), this, SLOT(receiveData()));
    connect(&rThread, SIGNAL(clearBtnSignal()),this, SLOT(clearScreen()));
}

void ReceiveWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    rect = event->rect();
    painter.drawImage(rect, image, rect);
}

void ReceiveWindow::drawLineTo()
{
    QPainter painter(&image);
    painter.drawLine(startPoint, endPoint);
    update();
}

void ReceiveWindow::receiveData()
{
    startPoint.setX(rThread.getSX());
    startPoint.setY(rThread.getSY());
    endPoint.setX(rThread.getEX());
    endPoint.setY(rThread.getEY());
    drawLineTo();
}
void ReceiveWindow::clearScreen()
{

    image.fill(qRgb(255,255,255));
    update();
}


void ReceiveWindow::setSX(int c)
{
    sCoordinateX=c;
}

void ReceiveWindow::setSY(int c)
{
    sCoordinateY=c;
}

void ReceiveWindow::setEX(int c)
{
    eCoordinateX=c;
}

void ReceiveWindow::setEY(int c)
{
    eCoordinateX=c;
}




