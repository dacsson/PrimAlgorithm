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
    // - Получить путь к файлу с материалом
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath(), "HTML file (*.html)");
    QFile TheoryFile(filename);

    // - Если с файлом что-то случилось (например пользователь удалил), то вызвать окно с ошибкой
    if(!TheoryFile.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", TheoryFile.errorString());

    // - Читаем весь файл и выводим в TextBox
    const QString Theory = QString::fromLocal8Bit(TheoryFile.readAll());
    ui -> TheoryDisplayBox -> setOpenExternalLinks(true);
    ui -> TheoryDisplayBox -> setHtml(Theory);
}

