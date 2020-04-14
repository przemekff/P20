#include "receivewindow.h"

ReceiveWindow::ReceiveWindow(QWidget *parent) : QWidget(parent)
{
    frame = new QFrame(this);
    frame->setFrameStyle(QFrame::StyledPanel);
    frame->setStyleSheet("background-color: rgb(255, 255, 255);");

    layout = new QVBoxLayout(this);
    layout->addWidget(frame,0,0);

}
