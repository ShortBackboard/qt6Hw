#include <QtGui>
#include "finddialog.h"


FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent),
    _label {new QLabel(tr("find &what"))},
    _lineEdit {new QLineEdit},
    _find {new QPushButton(tr("&find"))},
    _close {new QPushButton(tr("&close"))},
    _caseCheck {new QCheckBox(tr("&Match case"))},
    _searchCheck {new QCheckBox(tr("&Search backward"))}

{
    _label->setBuddy(_lineEdit);//设置伙伴

    _find->setDefault(true);
    _find->setEnabled(false);//设置不可选

    QHBoxLayout *topLeftLayout = new QHBoxLayout();
    topLeftLayout->addWidget(_label);
    topLeftLayout->addWidget(_lineEdit);

    QVBoxLayout *left = new QVBoxLayout();
    left->addLayout(topLeftLayout);
    left->addWidget(_caseCheck);
    left->addWidget(_searchCheck);

    QVBoxLayout *right = new QVBoxLayout();
    right->addWidget(_find);
    right->addWidget(_close);
    right->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(left);
    mainLayout->addLayout(right);

    setLayout(mainLayout);
    
    setWindowTitle(tr("Find"));//设置窗口标题
    setFixedHeight(sizeHint().height());//设置合适的固定窗口大小

    connect(_close, &QPushButton::clicked,
            this,&QApplication::quit);

    connect(_find, SIGNAL(clicked()),
            this,SLOT(findClicked()));

    connect(_lineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableFindButton(QString)));
}



void FindDialog::enableFindButton(const QString &text){
    _find->setEnabled(!text.isEmpty());
}

void FindDialog::findClicked(){
    QString text = _lineEdit->text();
    Qt::CaseSensitivity cs = _caseCheck->isChecked() ?
                Qt::CaseSensitive : Qt::CaseInsensitive;

    if(_searchCheck->isChecked()){
        emit findPrevious(text,cs);
    }else{
        emit findNext(text,cs);
    }


}
