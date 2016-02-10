#include "mainwindow.h"
#include "ui/mainwindowhandwritten.h"
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowHandwritten)
{
    ui->setupUi(this);


    QList<int> sizes = ui->splitter_viz_processing->sizes();
    std::cout << "MainWindow::MainWindow" << sizes[0] << " " << sizes[1] << std::endl;

    connect(ui->processing_toggle_btn, SIGNAL(clicked()), this, SLOT(printSizes()));
    //splitter_viz_processing->setSizes();

}

void MainWindow::printSizes()
{
    QList<int> sizes = ui->splitter_viz_processing->sizes();
    QSize qszhint = ui->splitter_viz_processing->sizeHint();
    QSize qsz = ui->splitter_viz_processing->size();

    std::cout << "MainWindow::printSizes " << sizes[0] << " " << sizes[1] << std::endl;
    std::cout << "MainWindow::printSizes " << "qsz.x=" << qsz.width() << " qsz.y=" << qsz.height() << std::endl;
    std::cout << "MainWindow::printSizes " << "qszhint.x=" << qszhint.width() << " qszhint.y=" << qszhint.height() << std::endl;
    std::cout << std::endl;

}

//void MyWidget::showEvent(QShowEvent *)
//{
//    QTimer::singleShot(50, this, SLOT(initializeDefaults());
//}

void MainWindow::initializeDefaults()
{
    ui->initializeDefaults(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Simu File"),"",tr("Simu output file (*.root)"));
}

void MainWindow::on_actionSelect_event_triggered()
{
    std::cout << "select event" << std::endl;
}

void MainWindow::on_actionNext_event_triggered()
{
    std::cout << "next event" << std::endl;
}

void MainWindow::on_actionRun_Reco_triggered()
{
    std::cout << "run reco" << std::endl;
}
