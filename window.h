#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QEvent>


class Window : public QWidget{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);

    void closeEvent(QCloseEvent *event);

    ~Window();
};



#endif // WINDOW_H
