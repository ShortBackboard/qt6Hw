/*
 *  chapter 01 : quit
 *  anthor:liChengYang
 *  date:2023-3-5
 *  version:
 *
*/
#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton *button = new QPushButton("quit");
    QObject::connect(button,&QPushButton::clicked,&app,&QApplication::quit);
    button->show();
    return app.exec();
}
