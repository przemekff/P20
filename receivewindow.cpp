#include "receivewindow.h"
#include "sharedPins.h"
#include <cmath>

ReceiveWindow::ReceiveWindow(QWidget *parent) : QWidget(parent)
{
    image = QImage(600,400,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    startPoint.setX(44);
    startPoint.setY(44);
    endPoint.setX(120);
    endPoint.setY(120);
    drawLineTo();
    rThread.start();
    connect(&rThread, SIGNAL(readingFinished()), this, SLOT(receiveData()));
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
    setSX(rThread.getSX());
    setSY(rThread.getSY());
    setEX(rThread.getEX());
    setEY(rThread.getEY());
    update();
    qDebug()<<"debug";
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




