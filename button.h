#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QDateTime>

class Button : public QPushButton{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);

    virtual bool event(QEvent *e) override;

signals:
    //小于300ms则认为是mouseClick，调用mouseClickEvent
    //信号
    void mouseClick();

private:
    QDateTime pressTime;//点击按钮时间
    QDateTime releaseTime;//释放按钮时间


};

#endif // BUTTON_H
