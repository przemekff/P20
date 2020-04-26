#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QImage>
#include <QSize>




class DrawingArea : public QWidget
{
public:
    DrawingArea(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void drawLineTo();
    void clearScreen();
protected:
    QPoint startPoint;
    QPoint endPoint;
    QImage image;
    QRect rect;
};

#endif // DRAWINGAREA_H
