#include "select_event_dialog.h"
#include "ui_select_event_dialog.h"
#include <iostream>

SelectEventDialog::SelectEventDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectEventDialog)
{
    ui->setupUi(this);
    std::cout << "after SETUP UI" << std::endl;
}

SelectEventDialog::~SelectEventDialog()
{
    delete ui;
}
