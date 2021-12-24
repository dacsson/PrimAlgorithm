#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "theorywindow.h"
#include "demonstrationwindow.h"
#include "testingwindow.h"
#include "demonstrationwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_TheoryButton_clicked();

    void on_TestButton_clicked();

    void on_DemonstrationButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
