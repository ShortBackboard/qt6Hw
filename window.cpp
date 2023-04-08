#include "window.h"

#include <QtDebug>
#include <QMouseEvent>
#include "label.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(50,50,600,600);

    _label = new Label{this};
}


bool Window::event(QEvent *e)
{
    //判断事件类型
    if(e->type() == QEvent::MouseMove){
        qDebug() << "move in" << "Window::event.";
        e->accept();

    }

    return QWidget::event(e);
}

Window::~Window()
{
}


