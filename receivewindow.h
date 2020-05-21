#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QImage>
#include <QLabel>
#include <QPainter>
#include <receivethread.h>
#include <drawingarea.h>
#include <cmath>
#include "sharedPins.h"

class ReceiveWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiveWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

    //function for drawing line between two QPoints
    void drawLineTo();

    //mutators for attributes
    void setSX(int c);
    void setSY(int c);
    void setEX(int c);
    void setEY(int c);

public slots:

    //function to be called after having read the data from sharedPins
    void receiveData();

    void clearScreen();

private:
    receiveThread rThread;
    int sCoordinateX;
    int sCoordinateY;
    int eCoordinateX;
    int eCoordinateY;
    QImage image;
    QRect rect;
    QPoint startPoint;
    QPoint endPoint;
};

#endif // RECEIVERWINDOW_H
