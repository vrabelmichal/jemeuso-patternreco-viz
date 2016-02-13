#ifndef RUNRECODIALOG_H
#define RUNRECODIALOG_H

#include <QWidget>

namespace Ui {
class RunRecoWindow;
}

class RunRecoWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RunRecoWindow(QWidget *parent = 0);
    ~RunRecoWindow();

signals:

public slots:


private:
    Ui::RunRecoWindow * ui;
};

#endif // RUNRECODIALOG_H
