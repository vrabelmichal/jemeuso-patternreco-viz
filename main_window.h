#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindowHandwritten;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initializeDefaults();

    //void show();

    //void showEvent(QShowEvent *) override;

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

    void on_actionSelect_event_triggered();

    void on_actionNext_event_triggered();

    void on_actionRun_Reco_triggered();

    void printSizes();

private:
    Ui::MainWindowHandwritten *ui;
};

#endif // MAINWINDOW_H
