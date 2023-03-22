/*
 * A program : FindDialog in book chapter02
 *
 * anthor:liChengYang
 * date:2023-3-5
 * version 2.0: write all codes in main function
 *              (can not find slots)
 *
*/

#include <QApplication>
#include <memory>
#include <QtGui>
#include <QtWidgets>
#include <QDialog>


using std::unique_ptr;
using std::make_unique;

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;


//slots:
void findNext(const QString &str,Qt::CaseSensitivity cs);
void findPrevious(const QString &str,Qt::CaseSensitivity cs);

void findClicked(QCheckBox* caseCheckBox,QCheckBox* backwardCheckBox,QLineEdit* lineEdit);
void enableFindButton(const QString &text,QPushButton* findButton);




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    auto window = make_unique<QWidget>();

    auto _label = new QLabel(QObject::tr("find &what"),window.get());//指定父对象
    auto _lineEdit = new QLineEdit(window.get());
    auto _find = new QPushButton(QObject::tr("&find"),window.get());
    auto _close = new QPushButton(QObject::tr("&close"),window.get());
    auto _caseCheck = new QCheckBox(QObject::tr("&Match case"),window.get());
    auto _searchCheck = new QCheckBox(QObject::tr("&Search backward"),window.get());


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

    window->setLayout(mainLayout);
    window->setWindowTitle(QObject::tr("Find"));//设置窗口标题
    window->setFixedHeight(window->sizeHint().height());//设置合适的固定窗口大小

    QObject::connect(_lineEdit,SIGNAL(textChanged(QString)),window.get(),
                     SLOT(enableFindButton(const QString&,_find)));

    QObject::connect(_find,SIGNAL(clicked()),window.get(),
                     SLOT(findClicked(_caseCheck,_searchCheck,_lineEdit)));

    QObject::connect(_close,&QPushButton::clicked,window.get(),
                    &QApplication::quit);

    window->show();

    return a.exec();
}


void enableFindButton(const QString &text,QPushButton* findButton){
    findButton->setEnabled(!text.isEmpty());
}

void findClicked(QCheckBox* caseCheckBox,QCheckBox* backwardCheckBox,QLineEdit* lineEdit){
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs =
        caseCheckBox->isChecked() ? Qt::CaseSensitive
                                  : Qt::CaseInsensitive;
    if(backwardCheckBox->isChecked()){
        emit findPrevious(text,cs);
    }else{
        emit findNext(text,cs);
    }
}

void findNext(const QString &str,Qt::CaseSensitivity cs){

}

void findPrevious(const QString &str,Qt::CaseSensitivity cs){

}





