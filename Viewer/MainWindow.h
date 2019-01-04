#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class DisplayScene;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
//    void initMenu


private:
    Ui::MainWindow *ui;

    DisplayScene *displayScene;
};

#endif // MAINWINDOW_H
