#ifndef SELECTEVENTDIALOG2_H
#define SELECTEVENTDIALOG2_H

#include <QDialog>

namespace Ui {
class SelectEventDialog;
}

class SelectEventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectEventDialog(QWidget *parent = 0);
    ~SelectEventDialog();

private:
    Ui::SelectEventDialog *ui;
};

#endif // SELECTEVENTDIALOG2_H
