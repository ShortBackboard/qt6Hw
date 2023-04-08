#ifndef LABELCHILD_H
#define LABELCHILD_H

#include <QLabel>
#include <QEvent>

class LabelChild : public QLabel{
public:
    LabelChild(QWidget *parent = nullptr);

    virtual bool event(QEvent *e) override;//事件处理
};

#endif // LABELCHILD_H
