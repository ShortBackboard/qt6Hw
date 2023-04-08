#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QEvent>


class Label : public QLabel
{
public:
    Label(QWidget *parent = nullptr);

    virtual bool event(QEvent *e) override;//事件处理


};

#endif // LABEL_H
