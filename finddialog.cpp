#include <QtGui>
#include "finddialog.h"


FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)

{
    //绑定父类，临时对象
    new QLabel(tr("find &what"),this);
    new QLineEdit(this);
    new QPushButton(tr("&find"),this);
    new QPushButton(tr("&close"),this);
    new QCheckBox(tr("&Match case"),this);
    new QCheckBox(tr("&Search backward"),this);

    //寻找孩子
    auto _label = this->findChild<QLabel *>();
    auto _lineEdit = this->findChild<QLineEdit *>();
    auto _checks = this->findChildren<QCheckBox *>();//返回列表
    auto _buttons = this->findChildren<QPushButton *>();

    _label->setBuddy(_lineEdit);//设置伙伴

    _buttons[0]->setDefault(true);
    _buttons[0]->setEnabled(false);//设置不可选

    setWindowTitle(tr("Find"));//设置窗口标题

    //设置布局
    this->setGeometry(0,0,260,110);
    _label->setGeometry(10,10,70,30);//x,y,w,h
    _lineEdit->setGeometry(80,15,70,20);
    _checks[0]->setGeometry(10,40,100,20);
    _checks[1]->setGeometry(10,70,100,20);
    _buttons[0]->setGeometry(180,30,50,30);
    _buttons[1]->setGeometry(180,60,50,30);

    connect(_buttons[1], &QPushButton::clicked,
            this,&QApplication::quit);

    connect(_buttons[0], SIGNAL(clicked()),
            this,SLOT(findClicked()));

    connect(_lineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableFindButton(QString)));
}



void FindDialog::enableFindButton(const QString &text){
    this->findChild<QPushButton *>()->setEnabled(!text.isEmpty());
}

void FindDialog::findClicked(){
    QString text = this->findChild<QLineEdit *>()->text();
    Qt::CaseSensitivity cs = this->findChild<QCheckBox *>()->isChecked() ?
                Qt::CaseSensitive : Qt::CaseInsensitive;

    if(this->findChild<QCheckBox *>()->isChecked()){
        emit findPrevious(text,cs);
    }else{
        emit findNext(text,cs);
    }
}
