#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TheoryButton_clicked()
{
    TheoryWindow *theoryWindow = new TheoryWindow;
    theoryWindow -> show();
}


void MainWindow::on_TestButton_clicked()
{
    TestingWindow *testintgWindow = new TestingWindow;
    testintgWindow -> show();
}


void MainWindow::on_DemonstrationButton_clicked()
{
    DemonstrationWindow *demonstrationWindow = new DemonstrationWindow;
    demonstrationWindow -> show();
}

