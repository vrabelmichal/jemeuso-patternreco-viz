#ifndef SELECTEVENTDIALOG2_H
#define SELECTEVENTDIALOG2_H

#include <QDialog>

namespace Ui {
class SelectEventDialog2;
}

class SelectEventDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit SelectEventDialog2(QWidget *parent = 0);
    ~SelectEventDialog2();

private:
    Ui::SelectEventDialog2 *ui;
};

#endif // SELECTEVENTDIALOG2_H
