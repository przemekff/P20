#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QImage>
#include <QSize>
#include <QDebug>
#include <sendingthread.h>




class DrawingArea : public QWidget
{

public:
    DrawingArea(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void drawLineTo();
    void clearScreen();
    void serialize(int point, bool *data);
    void serializeAll();
private:
    SendingThread sThread;
    QPoint startPoint;
    QPoint endPoint;
    QImage image;
    QRect rect;
    bool sCoordinateX[10];
    bool sCoordinateY[10];
    bool eCoordinateX[10];
    bool eCoordinateY[10];


};

#endif // DRAWINGAREA_H
