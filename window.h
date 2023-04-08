#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QEvent>
class Label;

class Window : public QWidget{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    virtual bool event(QEvent *event) override;//事件处理
    ~Window();

private:
    Label *_label;//子类
};



#endif // WINDOW_H
