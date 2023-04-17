#include "window.h"

#include "button.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{

    setGeometry(400,300,100,90);

    _button = new Button{this};

}



Window::~Window()
{
}
