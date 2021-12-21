#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>
#include <QDir>

class FileManager
{
public:
    FileManager();
    QString DatabaseFile_PATH;      // - Путь к БД с вопросами
    QString TheoryFile_PATH;        // - Путь к файлу с теорией
private:
    void GetPathsFromConfig();      // - Получиь пути к файлам с лекцией и тестированием из файла с конфигурацией
};

#endif // FILEMANAGER_H
