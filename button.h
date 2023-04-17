#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QEvent>


class Button : public QPushButton{
    Q_OBJECT
public:
    Button(QWidget *parent = nullptr);

protected:
    virtual bool event(QEvent *e) override;
    virtual void timerEvent(QTimerEvent *e) override;

private:
    void mouseClick();

private:
    int m_timerId;//定时器Id

};

#endif // BUTTON_H
