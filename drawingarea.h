#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QImage>



class DrawingArea : public QWidget
{
public:
    DrawingArea(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
protected:
    QPoint startPoint;
    QPoint endPoint;
    QImage image;
};

#endif // DRAWINGAREA_H
