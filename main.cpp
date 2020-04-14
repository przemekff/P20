#include "sendwindow.h"
#include "receivewindow.h"


#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SendWindow s;
    s.resize(600, 400);
    s.setWindowTitle("Send Window");
    s.show();

    ReceiveWindow r;
    r.resize(600, 400);
    r.setWindowTitle("Receive Window");
    r.show();
    return a.exec();
}
