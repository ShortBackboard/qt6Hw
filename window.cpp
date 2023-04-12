#include "window.h"

#include <QtDebug>
#include <QMouseEvent>


Window::Window(QWidget *parent)
    : QWidget(parent)
{

}

void Window::closeEvent(QCloseEvent *event)
{
    event->ignore();//忽略此事件,继续向父类传递
    //event->accept();
    qDebug() <<"closeEvent";
}


Window::~Window()
{
}


