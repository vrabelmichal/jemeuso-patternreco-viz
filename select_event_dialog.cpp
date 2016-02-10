#include "selecteventdialog2.h"
#include "ui_selecteventdialog2.h"

SelectEventDialog2::SelectEventDialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectEventDialog2)
{
    ui->setupUi(this);
}

SelectEventDialog2::~SelectEventDialog2()
{
    delete ui;
}
