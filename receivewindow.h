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

class ReceiveWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiveWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void drawLineTo();
    void setSX(int c);
    void setSY(int c);
    void setEX(int c);
    void setEY(int c);
public slots:
    void receiveData();
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
