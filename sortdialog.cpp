#include "sortdialog.h"
#include "ui_sort.h"
#include <iostream>

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sort_bridge)
{
    ui->setupUi(this);

    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A', 'Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    ui->primaryColumnCombo->clear();
    ui->secondaryColumnCombo->clear();
    ui->tertiaryColumnCombo->clear();

    ui->secondaryColumnCombo->addItem("None");
    ui->tertiaryColumnCombo->addItem("None");

    ui->primaryColumnCombo->setMinimumSize(ui->secondaryColumnCombo->sizeHint());
    QChar ch = first;
    while(ch <= last){
        ui->primaryColumnCombo->addItem(QString(ch));
        ui->secondaryColumnCombo->addItem(QString(ch));
        ui->tertiaryColumnCombo->addItem(QString(ch));
//        std::cerr << std::showbase << std::hex << ch.unicode() << '\n'; //only valid in c++17
        ch = ++(ch.unicode());
    }
}

int SortDialog::primaryColumnComboCurrentIndex()
{
    return ui->primaryColumnCombo->currentIndex();
}

int SortDialog::secondaryColumnComboCurrentIndex()
{
    return ui->secondaryColumnCombo->currentIndex();
}

int SortDialog::tertiaryColumnComboCurrentIndex()
{
    return ui->tertiaryColumnCombo->currentIndex();
}

int SortDialog::primaryOrderComboCurrentIndex()
{
    return ui->primaryOrderCombo->currentIndex();
}

int SortDialog::secondaryOrderComboCurrentIndex()
{
    return ui->secondaryOrderCombo->currentIndex();
}

int SortDialog::tertiaryOrderComboCurrentIndex()
{
    return ui->tertiaryOrderCombo->currentIndex();
}


SortDialog::~SortDialog()
{
    delete ui;
}
