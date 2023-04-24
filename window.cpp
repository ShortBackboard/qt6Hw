#include "window.h"

#include <QFileDialog>

#include "ui_window.h"
#include "finddialog.h"
#include "gotocelldialog.h"
#include "sortdialog.h"
#include "ui_sort.h"

#include <QTableWidgetSelectionRange>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    findDialog(nullptr),
    goToCellDialog(nullptr),
    locationLabel(nullptr),
    formulaLabel(nullptr),
    sortDialog(nullptr),
    _ui(new Ui::Window)
{
    _ui->setupUi(this);

    setUpActions();
    createContextMenu();
    createStatusBar();

    //    readSettings();

    findDialog = nullptr;

    setWindowIcon(QIcon(":/images/icon.png"));

}

Window::~Window()
{
    delete _ui;
}

void Window::setUpActions()
{
    for (auto &a:recentFileActions) {
        a = new QAction(this);
        a->setVisible(false);
        connect(a, &QAction::triggered, this, &Window::openRecentFile);
    }

    //    QAction *saveAction = new QAction(tr("&Save"), this);

    _ui->action_Save->setIcon(QIcon(":/images/save"));
    _ui->action_Save->setShortcut(QKeySequence::Save);
    _ui->action_Save->setStatusTip(tr("Save the spreadsheet to disk"));

    //    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

}

void Window::openRecentFile()
{
    qDebug() << "todo: openRecentFile";
}

void Window::createContextMenu()
{
    _ui->spreadsheet->addAction(_ui->actionCu_t);
    _ui->spreadsheet->addAction(_ui->action_copy);
    _ui->spreadsheet->addAction(_ui->action_Paste);
    _ui->spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void Window::createStatusBar()
{
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);

    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    connect(_ui->spreadsheet, &Spreadsheet::currentCellChanged,
            this, &Window::updateStatusBar);
    connect(_ui->spreadsheet, &Spreadsheet::modified,
            this, &Window::spreadsheetModified);

    updateStatusBar();
}

void Window::updateStatusBar()
{
    locationLabel->setText(_ui->spreadsheet->currentLocation());
    formulaLabel->setText(_ui->spreadsheet->currentFormula());
}

void Window::spreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}





void Window::on_action_Go_to_Cell_triggered()
{
    GoToCellDialog dialog(this);
    if (dialog.exec()) {
        QString str = dialog.getCellLocation();
        _ui->spreadsheet->setCurrentCell(str.mid(1).toInt() -1,
                                         str[0].unicode() - 'A');
    }
}


void Window::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Spreadsheet"), ".",
                                                    tr("Spreadsheet files (*.sp)"));
    if (!fileName.isEmpty())
        qDebug()<<"todo: loadFile(fileName)" << fileName;
}


void Window::on_action_Find_triggered()
{
    if (!findDialog) {
        findDialog = new FindDialog(this);
        connect(findDialog, &FindDialog::findNext,
                _ui->spreadsheet, &Spreadsheet::findNext);
        connect(findDialog, &FindDialog::findPrevious,
                _ui->spreadsheet, &Spreadsheet::findPrevious);
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();
}


void Window::on_action_Sort_triggered()
{
    sortDialog = new SortDialog(this);


    QTableWidgetSelectionRange range = _ui->spreadsheet->selectedRange();
    sortDialog->setColumnRange(QChar('A' + range.leftColumn()),
                              QChar('A' + range.rightColumn()) );

    if (sortDialog->exec()) {
        SpreadsheetCompare compare;
        compare.keys[0] = sortDialog->ui->
                          primaryColumnCombo->currentIndex();
        compare.keys[1] = sortDialog->ui->
                          secondaryColumnCombo->currentIndex() - 1;
        compare.keys[2] = sortDialog->ui->
                          tertiaryColumnCombo->currentIndex() - 1;
        compare.ascending[0] =
            (sortDialog->ui->primaryOrderCombo->currentIndex() == 0);
        compare.ascending[1] =
            (sortDialog->ui->secondaryOrderCombo->currentIndex() == 0);
        compare.ascending[2] =
            (sortDialog->ui->tertiaryOrderCombo->currentIndex() == 0);
        _ui->spreadsheet->sort(compare);
    }
}



