#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
class Button;

class Window : public QWidget{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private:
    Button *_button;//子类
};

#endif // WINDOW_H
