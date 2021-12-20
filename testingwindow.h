#ifndef TESTINGWINDOW_H
#define TESTINGWINDOW_H

#include <QDialog>

namespace Ui {
class TestingWindow;
}

class TestingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TestingWindow(QWidget *parent = nullptr);
    ~TestingWindow();

private:
    Ui::TestingWindow *ui;
};

#endif // TESTINGWINDOW_H
