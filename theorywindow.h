#ifndef THEORYWINDOW_H
#define THEORYWINDOW_H

#include <QDialog>
#include <QTextBrowser>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

namespace Ui {
class TheoryWindow;
}

class TheoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TheoryWindow(QWidget *parent = nullptr);
    ~TheoryWindow();

private:
    Ui::TheoryWindow *ui;
    void DisplayTheoryFile();   // - Вывести HTML файл на экран
};

#endif // THEORYWINDOW_H
