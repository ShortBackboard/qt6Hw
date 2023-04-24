#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include "spreadsheet.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bridge)
{
    ui->setupUi(this);

    auto sp = new Spreadsheet(this);
    setCentralWidget(sp);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_open_triggered()
{
    qDebug() << "todo:open file.";
}

