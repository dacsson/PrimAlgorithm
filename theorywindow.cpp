#include "theorywindow.h"
#include "ui_theorywindow.h"

TheoryWindow::TheoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TheoryWindow)
{
    ui->setupUi(this);

    DisplayTheoryFile();
}

TheoryWindow::~TheoryWindow()
{
    delete ui;
}

void TheoryWindow::DisplayTheoryFile()
{
    // - Получить путь к файлу с материалом из файла с конфигурацией (файл с конфигом находится в домашней папке юзера), путь к файлу возникает в файле с конфигурацией в момент инсталляции
    QString configName = "ApplicationConfig.json";                              // - Название конфиг файла, вместо Application ввести имя своего приложения
    QFile configFile(QDir::homePath() + "/" + configName);                      // - Путь к файлу конфигурации

    // - Если файла с конфигом не существует (например пользователь удалил), то вызвать окно с ошибкой
    if( !configFile.open( QIODevice::ReadOnly ) )
        QMessageBox::information(0, "info", configFile.errorString());

    QByteArray configFile_bytes = configFile.readAll();                         // - Читаем содрежимое файла конфигурации
    auto configFile_doc = QJsonDocument::fromJson(configFile_bytes);
    QJsonObject configFile_obj = configFile_doc.object();
    QVariantMap configFile_map = configFile_obj.toVariantMap();
    QString TheoryFile_PATH = configFile_map["TheoryFile_PATH"].toString();     // - Берём путь к файлу по пути из файла конфигурации по ключу

    // - Загружаме файл по полученному пути
    QFile TheoryFile(TheoryFile_PATH);

    // ! Другой вариант задать абсолютный путь (не рабочий вариант при создании инсталлятора)
    // QFile TheoryFile("D:/University/Lectures/Material.html");

    // ! Другой вариант просить пользователя загрузить файл собственноручно (допустимый вариант)
    //  QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath(), "HTML file (*.html)");
    //  QFile TheoryFile(filename);

    // - Если с файлом что-то случилось (например пользователь удалил), то вызвать окно с ошибкой
    if(!TheoryFile.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", TheoryFile.errorString());

    // - Читаем весь файл и выводим в TextBox
    const QString Theory = QString::fromLocal8Bit(TheoryFile.readAll());
    ui -> TheoryDisplayBox -> setOpenExternalLinks(true);
    ui -> TheoryDisplayBox -> setHtml(Theory);
}

