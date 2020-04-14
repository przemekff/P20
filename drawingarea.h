#ifndef DRAWINGAREA_H
#define DRAWINGAREA_H

#include <QWidget>
#include <QMouseEvent>



class DrawingArea : public QWidget
{
public:
    DrawingArea(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // DRAWINGAREA_H
