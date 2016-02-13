#include "run_reco_window.h"
#include <ui_run_reco_window.h>

RunRecoWindow::RunRecoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RunRecoWindow)
{
    ui->setupUi(this);
}

RunRecoWindow::~RunRecoWindow()
{
    delete ui;
}
