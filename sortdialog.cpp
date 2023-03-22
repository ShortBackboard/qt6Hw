#include "sortdialog.h"
#include "ui_sortdialog.h"
#include <QtGui>


sortdialog::sortdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortDialog)
{
    ui->setupUi(this);

    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A','Z');
}

void sortdialog::setColumnRange(QChar first, QChar last){
    ui->primaryColumnCombo->clear();
    ui->secondaryColumnCombo->clear();
    ui->tertiaryColumnCombo->clear();

    ui->secondaryColumnCombo->addItem(tr("None"));
    ui->tertiaryColumnCombo->addItem(tr("None"));
    ui->primaryColumnCombo->setMinimumSize(
        ui->secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while(ch <= last){
        ui->primaryColumnCombo->addItem(QString(ch));
        ui->secondaryColumnCombo->addItem(QString(ch));
        ui->tertiaryColumnCombo->addItem(QString(ch));
        ch = (QChar)(ch.unicode() + 1);
    }
}

sortdialog::~sortdialog()
{
    delete ui;
}

