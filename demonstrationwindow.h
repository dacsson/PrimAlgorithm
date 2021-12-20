#ifndef DEMONSTRATIONWINDOW_H
#define DEMONSTRATIONWINDOW_H

#include <QDialog>

namespace Ui {
class DemonstrationWindow;
}

class DemonstrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DemonstrationWindow(QWidget *parent = nullptr);
    ~DemonstrationWindow();

private:
    Ui::DemonstrationWindow *ui;
};

#endif // DEMONSTRATIONWINDOW_H
