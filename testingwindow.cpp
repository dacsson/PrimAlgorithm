#include "testingwindow.h"
#include "ui_testingwindow.h"

TestingWindow::TestingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestingWindow)
{
    ui->setupUi(this);

    DisplayFirstQuestion();
}

TestingWindow::~TestingWindow()
{
    delete ui;
}

void TestingWindow::DisplayFirstQuestion()
{
    // - Получаем путь к БД из менеджера файлов (FileManager.h)
    FileManager FManager;
    QString DatabaseFile_PATH = FManager.DatabaseFile_PATH;

    // - Загружаме БД по полученному пути
    QSqlDatabase QuestionsDB = QSqlDatabase::addDatabase("QSQLITE");
    QuestionsDB.setDatabaseName(DatabaseFile_PATH);

    // - Если БД не существует (например пользователь удалил), то вызвать окно с ошибкой
    if( !QuestionsDB.open( ) )
        return;

    query = QSqlQuery(QuestionsDB);
    query.prepare("select * from questions");
    query.exec();

    query.first();
    ui -> QuestionTextBox -> setText(query.value("TEXT").toString());
    ui -> option1TextBox -> setText(query.value("OPTION1").toString());
    ui -> option2TextBox -> setText(query.value("OPTION2").toString());
    ui -> option3TextBox -> setText(query.value("OPTION3").toString());
    ui -> option4TextBox -> setText(query.value("OPTION4").toString());
    ui -> option5TextBox -> setText(query.value("OPTION5").toString());
}

void TestingWindow::on_nextQuestion_clicked()
{
    DisplayNextQuestion();
}

void TestingWindow::DisplayNextQuestion()
{
    if(query.next())
    {
        // - Если в БД далее есть записи то считываем & выводим следующую
        ui -> QuestionTextBox -> setText(query.value("TEXT").toString());
        ui -> option1TextBox -> setText(query.value("OPTION1").toString());
        ui -> option2TextBox -> setText(query.value("OPTION2").toString());
        ui -> option3TextBox -> setText(query.value("OPTION3").toString());
        ui -> option4TextBox -> setText(query.value("OPTION4").toString());
        ui -> option5TextBox -> setText(query.value("OPTION5").toString());

        // - Обновляем номер вопроса
        questionNumber++;

        // - Очищаем интерфейс
        ClearUI();
    }
    else
    {
        // - Если записи кончились, то выводим окно с результатами
        int score = CalculateUserScore();
//        int mark = CalculateUserMark(score);
        QMessageBox::information(0, "Конец тестирования", "Ваш результат: " + QString::number(score) + " из " + QString::number(userAnswers.size()) + "\nВаша оценка: " + QString::number(CalculateUserMark(score)));
    }
}

void TestingWindow::on_option1Button_clicked() { registerAnswer(1); }

void TestingWindow::on_option2Button_clicked() { registerAnswer(2); }

void TestingWindow::on_option3Button_clicked() { registerAnswer(3); }

void TestingWindow::on_option4Button_clicked() { registerAnswer(4); }

void TestingWindow::on_option5Button_clicked() { registerAnswer(5); }

void TestingWindow::registerAnswer(int index)
{
    if(index == query.value("RIGHTANSWER"))
    {
        // - Если ответ совпадает с верным (из БД) то заносим в вектор 1
        userAnswers.push_back(1);
    }
    else
    {
        // - Иначе 0
        userAnswers.push_back(0);
    }
}

int TestingWindow::CalculateUserScore()
{
    int score = 0;
    for(size_t i = 0; i < userAnswers.size(); i++)
    {
        // - Если элемент == 1 -> ответ верный, считаем как 1 балл
        if(userAnswers[i])
            score++;
    }
    return score;
}

int TestingWindow::CalculateUserMark(int score)
{
    // - Оценить пользователя
    int mark;
    if(score < 10) { mark = 2; }
    else if(score < 15) { mark = 3; }
    else if(score < 20) { mark = 4; }
    else { mark = 5; }

    return mark;
}

void TestingWindow::ClearUI()
{
    ui -> option1Button -> setAutoExclusive(false);
    ui -> option1Button -> setChecked(false);
    ui -> option1Button -> setAutoExclusive(true);

    ui -> option2Button -> setAutoExclusive(false);
    ui -> option2Button -> setChecked(false);
    ui -> option2Button -> setAutoExclusive(true);

    ui -> option3Button -> setAutoExclusive(false);
    ui -> option3Button -> setChecked(false);
    ui -> option3Button -> setAutoExclusive(true);

    ui -> option4Button -> setAutoExclusive(false);
    ui -> option4Button -> setChecked(false);
    ui -> option4Button -> setAutoExclusive(true);

    ui -> option5Button -> setAutoExclusive(false);
    ui -> option5Button -> setChecked(false);
    ui -> option5Button -> setAutoExclusive(true);
}
