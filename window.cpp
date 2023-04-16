#include "window.h"

#include "button.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{

    setGeometry(400,300,100,90);

    _button = new Button{this};

    QObject::connect(_button, &Button::mouseClick,
                     this, &Window::mouseClickEvent);


}


//槽函数
//关闭窗口
void Window::mouseClickEvent()
{
    exit(0);
}



Window::~Window()
{
}
