#include "drawingarea.h"

DrawingArea::DrawingArea(QWidget *parent) : QWidget(parent)
{
    image = QImage(600,400,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
}

void DrawingArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
        startPoint = event->pos();
}

void DrawingArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
        endPoint = event->pos();
    drawLineTo();
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
