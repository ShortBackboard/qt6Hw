#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
class Button;

class Window : public QWidget{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

public slots:
    //槽函数
    void mouseClickEvent();

private:
    Button *_button;//子类
};

#endif // WINDOW_H
