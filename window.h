#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QEvent>
class Label;

class Window : public QWidget{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

    virtual bool event(QEvent *e) override;//事件处理

    //重写基类的eventfilter方法,事件过滤捕获
    bool eventFilter(QObject *watched, QEvent *event);

    ~Window();

private:
    Label *_label;//子类
};



#endif // WINDOW_H
