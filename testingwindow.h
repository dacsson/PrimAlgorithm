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

    void on_option1Button_clicked();
    void on_option2Button_clicked();
    void on_option3Button_clicked();
    void on_option4Button_clicked();
    void on_option5Button_clicked();

private:
    Ui::TestingWindow *ui;
    std::vector<int> userAnswers;                   // - Вектор ответов пользователя на вопросы
    int questionNumber = 0;                         // - Номер вопроса на экране
    QSqlQuery query;                                // - Очередь из БД
    void DisplayFirstQuestion();                    // - Вывести первый вопрос из SQLite базы на экран при запуске
    void DisplayNextQuestion();                     // - Вывести следующий вопрос
    void registerAnswer(int index);                 // - Принять ответ пользователя на вопрос
    int CalculateUserScore();                       // - Посчитать результат пользователя (кол-во баллов)
    void ClearUI();                                 // - Удалить точки с радиокнопок при переходе на следующий вопрос
};

#endif // TESTINGWINDOW_H
