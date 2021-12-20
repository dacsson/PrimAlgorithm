#include "testingwindow.h"
#include "ui_testingwindow.h"

TestingWindow::TestingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestingWindow)
{
    ui->setupUi(this);
}

TestingWindow::~TestingWindow()
{
    delete ui;
}
