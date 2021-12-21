#include "testingwindow.h"
#include "ui_testingwindow.h"

TestingWindow::TestingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestingWindow)
{
    ui->setupUi(this);

    DisplayQuestions();
}

TestingWindow::~TestingWindow()
{
    delete ui;
}

void TestingWindow::DisplayQuestions()
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

    QSqlQuery *query = new QSqlQuery(QuestionsDB);
    query -> prepare("select * from questions");
    query -> exec();

    query->first();
    ui -> QuestionTextBox -> setText(query->value("TEXT").toString());
}
