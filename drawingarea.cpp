#include "drawingarea.h"

DrawingArea::DrawingArea(QWidget *parent) : QWidget(parent)
{
    image.fill(qRgb(0, 0, 0));
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
    repaint();
}

void DrawingArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, image, rect);
    painter.drawLine(startPoint, endPoint);

}
