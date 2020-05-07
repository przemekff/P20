#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QImage>
#include <QSize>
#include <QDebug>




class DrawingArea : public QWidget
{
Q_OBJECT
public:
    DrawingArea(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void drawLineTo();
    void clearScreen();
    void serialize(int point, bool *data);
    void serializeAll ();

signals:
    bool* dataCollected();

private:
    QPoint startPoint;
    QPoint endPoint;
    QImage image;
    QRect rect;
    bool sCoordinateX[8];
    bool sCordinateY[8];
    bool eCoordinateX[8];
    bool eCordinateY[8];


};

#endif // DRAWINGAREA_H
