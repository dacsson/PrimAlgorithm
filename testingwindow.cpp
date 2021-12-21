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
    query.next();
    ui -> QuestionTextBox -> setText(query.value("TEXT").toString());
    ui -> option1TextBox -> setText(query.value("OPTION1").toString());
    ui -> option2TextBox -> setText(query.value("OPTION2").toString());
    ui -> option3TextBox -> setText(query.value("OPTION3").toString());
    ui -> option4TextBox -> setText(query.value("OPTION4").toString());
    ui -> option5TextBox -> setText(query.value("OPTION5").toString());
}
