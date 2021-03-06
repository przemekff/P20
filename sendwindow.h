#ifndef SENDWINDOW_H
#define SENDWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include "drawingarea.h"

class SendWindow : public QWidget
{

Q_OBJECT

public:
    explicit SendWindow(QWidget *parent = 0);    

private slots:
    //slot performing operation after the clearBtn is clicked
    void handleButton();

private:
    QPushButton *quitBtn;
    QPushButton *clearBtn;
    QVBoxLayout *layout;
    DrawingArea *area;

};

#endif // SENDWINDOW_H
