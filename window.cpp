#include "window.h"

#include <QtDebug>
#include <QMouseEvent>
#include "label.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(50,50,600,600);

    _label = new Label{this};

    //给标签安装事件过滤器
    //任意对象都可以提前拦截其他任意对象的事件，拦截到的事件都会在本对象的eventFilter函数中被接收到，程序员可以决定拦截并处理后是否继续放行。
    _label->installEventFilter(this);
}

bool Window::event(QEvent *e)
{
    if(e->type() == QEvent::MouseMove){
        qDebug() << "move in" << "Window::event.";
        e->accept();
        //return true;//则事件不会继续传递
    }

    return QWidget::event(e);
}

//事件过滤器
bool Window::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == _label && event->type() == QEvent::MouseMove){
        qDebug() << "move in" << "Window::eventFilter.";
        //return true; //不再向下传递事件
    }

    return QWidget::eventFilter(watched,event);
}




Window::~Window()
{
}


