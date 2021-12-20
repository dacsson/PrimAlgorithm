#include "demonstrationwindow.h"
#include "ui_demonstrationwindow.h"

DemonstrationWindow::DemonstrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DemonstrationWindow)
{
    ui->setupUi(this);
}

DemonstrationWindow::~DemonstrationWindow()
{
    delete ui;
}
