#include "filemanager.h"

FileManager::FileManager()
{
    GetPathsFromConfig();
}

void FileManager::GetPathsFromConfig()
{
    // - Получить путь к БД с материалом из файла с конфигурацией (файл с конфигом находится в домашней папке юзера), путь к файлу возникает в файле с конфигурацией в момент инсталляции
    QString configName = "ApplicationConfig.json";                              // - Название конфиг файла, вместо Application ввести имя своего приложения
    QFile configFile(QDir::homePath() + "/" + configName);                      // - Путь к файлу конфигурации

    // - Если файла с конфигом не существует (например пользователь удалил), то вызвать окно с ошибкой
    if( !configFile.open( QIODevice::ReadOnly ) )
        QMessageBox::information(0, "info", configFile.errorString());

    // ! Другой вариант задать абсолютный путь (не рабочий вариант при создании инсталлятора)
    // QFile TheoryFile("D:/University/Lectures/Material.html");

    // ! Другой вариант просить пользователя загрузить файл собственноручно (допустимый вариант)
    //  QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath(), "HTML file (*.html)");
    //  QFile TheoryFile(filename);

    QByteArray configFile_bytes = configFile.readAll();                         // - Читаем содрежимое файла конфигурации
    auto configFile_doc = QJsonDocument::fromJson(configFile_bytes);
    QJsonObject configFile_obj = configFile_doc.object();
    QVariantMap configFile_map = configFile_obj.toVariantMap();

    DatabaseFile_PATH = configFile_map["DatabaseFile_PATH"].toString();         // - Берём путь к БД из файла конфигурации по ключу
    TheoryFile_PATH = configFile_map["TheoryFile_PATH"].toString();             // - Берём путь к HTML из файла конфигурации по ключу
}
