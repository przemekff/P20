#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QImage>
#include <drawingarea.h>

class ReceiveWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiveWindow(QWidget *parent = nullptr);
    int deserialize(bool* data);

signals:
    void ready();

private:
    QImage image;

};

#endif // RECEIVERWINDOW_H
