#include "drawingarea.h"
#include "sharedPins.h"


DrawingArea::DrawingArea(QWidget *parent) : QWidget(parent)
{
    image = QImage(600,400,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
        startPoint = event->pos();
    serializeAll();
    sThread.setData(sCoordinateX,sCoordinateY);
    sThread.start();
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
        endPoint = event->pos();
    drawLineTo();
    serializeAll();
}

void DrawingArea::drawLineTo()
{
    QPainter painter(&image);
    painter.drawLine(startPoint, endPoint);
    update();
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    rect = event->rect();
    painter.drawImage(rect, image, rect);

}

void DrawingArea::clearScreen()
{
    image.fill(qRgb(255,255,255));
    update();
}

void DrawingArea::serialize(int point, bool *data)
{
    for(int i=7;i>=0;i--)
    {
        if(point%2 == 0)
            data[i] = 0;
        else
            data[i] = 1;
        point /= 2;

    }
}


void DrawingArea::serializeAll()
{
    serialize(startPoint.rx(),sCoordinateX);
    serialize(startPoint.ry(),sCoordinateY);
    serialize(endPoint.rx(),eCoordinateX);
    serialize(endPoint.ry(),eCoordinateY);

}
