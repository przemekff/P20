#include "drawingarea.h"
#include "sharedPins.h"


DrawingArea::DrawingArea(QWidget *parent) : QWidget(parent)
{
    //creating an empty image, making it white
    image = QImage(600,400,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    //saving position of the click to drawingArea class attribute
    if (event->button() & Qt::LeftButton)
        startPoint = event->pos();

    //making sure correct data is getting serialized
    serialize(startPoint.rx(),sCoordinateX);
    serialize(startPoint.ry(),sCoordinateY);

    //setting data attribute of the thread as starting point coordinates
    sThread.setData(sCoordinateX,sCoordinateY);
    sThread.start();

    //singalling that it is the starting point data that is being sent
    sharedPins[20]=1;
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *event)
{
    //saving position of the click to drawingArea class attribute
    if (event->button() & Qt::LeftButton)
        endPoint = event->pos();

    //drawing the line between start and endpoint
    drawLineTo();
    serialize(endPoint.rx(),eCoordinateX);
    serialize(endPoint.ry(),eCoordinateY);
    sThread.setData(eCoordinateX,eCoordinateY);
    sThread.start();

    //singalling that it is the ending point data that is being sent
    sharedPins[20]=0;


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
    for(int i=9;i>=0;i--)
    {
        if(point%2 == 0)
            data[i] = 0;
        else
            data[i] = 1;
        point /= 2;

    }
}

void DrawingArea::handleClearButton()
{
    sharedPins[10] = 1;
}

