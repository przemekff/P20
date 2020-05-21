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

Q_OBJECT

public:
    //constructor
    DrawingArea(QWidget *parent = 0);

    //overriding the default functions for handling events
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

    //function for drawing line between two QPoints
    void drawLineTo();

    //replacing the image with a blank one
    void clearScreen();

    /*
     converting int to array of bools
     @param point The int to be converted
     @param data The target array
    */
    void serialize(int point, bool *data);

public slots:
    void handleClearButton();

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
