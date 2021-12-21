#ifndef TESTINGWINDOW_H
#define TESTINGWINDOW_H

#include "filemanager.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QtDebug>

namespace Ui {
class TestingWindow;
}

class TestingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TestingWindow(QWidget *parent = nullptr);
    ~TestingWindow();

private slots:
    void on_nextQuestion_clicked();

private:
    Ui::TestingWindow *ui;
    QSqlQuery query;                                // - Очередь из БД
    void DisplayFirstQuestion();                    // - Вывести первый вопрос из SQLite базы на экран при запуске
    void DisplayNextQuestion();                     // - Вывести следующий вопрос
};

#endif // TESTINGWINDOW_H
