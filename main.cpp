/*
 *  chapter 01 : hello
 *  A program that get started Hello Qt,using unique_ptr preventing memory leak.
 *  anthor:liChengYang
 *  date:2023-3-5
 *  version:
 *
*/
#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::unique_ptr<QLabel> label = std::make_unique<QLabel>("<h2><i>Hello</i>"
                                                             "<font color=red>Qt!</font></h2>");


    label->show();
    return a.exec();
}
