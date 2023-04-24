#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <array>
#include <QLabel>

namespace Ui {
class Window;
}

class FindDialog;
class GoToCellDialog;
class SortDialog;

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:


    void on_action_Go_to_Cell_triggered();

    void on_action_Open_triggered();

    void on_action_Find_triggered();

    void on_action_Sort_triggered();

private:
    void setUpActions();
    void openRecentFile();
    void createContextMenu();
    void createStatusBar();
    void updateStatusBar();
    void spreadsheetModified();



    enum { MaxRecentFiles = 5 };
    std::array<QAction *, MaxRecentFiles> recentFileActions;

    SortDialog *sortDialog;
    FindDialog *findDialog;
    GoToCellDialog *goToCellDialog;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    Ui::Window *_ui;
};

#endif // WINDOW_H
