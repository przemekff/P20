#ifndef RECEIVERWINDOW_H
#define RECEIVERWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>

class ReceiveWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ReceiveWindow(QWidget *parent = nullptr);

private:
    QFrame *frame;
    QVBoxLayout *layout;

};

#endif // RECEIVERWINDOW_H
