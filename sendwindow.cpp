#include "sendwindow.h"


SendWindow::SendWindow(QWidget *parent)
    : QWidget(parent)
{

      layout = new QVBoxLayout(this);

      quitBtn = new QPushButton("Quit", this);
      connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

      area = new DrawingArea(this);
      area->setStyleSheet("background-color:white;");

      clearBtn = new QPushButton("Clear", this);
      connect(clearBtn, SIGNAL (released()), this, SLOT (handleButton()));
      connect(clearBtn, SIGNAL(released()), area, SLOT (handleClearButton()));



      layout->addWidget(area,0,0);
      layout->addWidget(clearBtn, 0,0);
      layout->addWidget(quitBtn, 0,0);


}

void SendWindow::handleButton()
{
    area->clearScreen();
}
