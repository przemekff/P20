#include "sendwindow.h"
#include "receivewindow.h"
#include "drawingarea.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating sending window, setting its size and title
    SendWindow s;
    s.resize(600, 400);
    s.setWindowTitle("Send Window");
    s.show();

    //creating receive window, setting its size and title
    ReceiveWindow r;
    r.resize(600, 400);
    r.setWindowTitle("Receive Window");
    r.show();


    return a.exec();
}
