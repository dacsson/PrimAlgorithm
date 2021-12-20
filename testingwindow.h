#ifndef TESTINGWINDOW_H
#define TESTINGWINDOW_H

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

private:
    Ui::TestingWindow *ui;
    void DisplayQuestions();    // - Вывести вопросы из SQLite базы на экран
};

#endif // TESTINGWINDOW_H
