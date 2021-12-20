#ifndef THEORY_H
#define THEORY_H

#include <QObject>
#include <QWidget>
#include <QTextBrowser>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QMainWindow>
#include <mainwindow.h>

class Theory
{
public:
    QMainWindow MainWindow = MainWindow;
    Theory();
    void ReadFile(QString Path);         //считать файл с лекцией
    void ShowFile(QTextBrowser Text);    //вывести содержимое файла на экран
};

#endif // THEORY_H
