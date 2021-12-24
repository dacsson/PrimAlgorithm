#include "demonstrationwindow.h"
#include "ui_demonstrationwindow.h"

DemonstrationWindow::DemonstrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DemonstrationWindow)
{
    ui->setupUi(this);

    ui->DescriptionTextBox->setText(Messages[0]);
}

DemonstrationWindow::~DemonstrationWindow()
{
    delete ui;
}

void DemonstrationWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    DrawGraph(&painter);
}

void DemonstrationWindow::DrawGraph(QPainter *painter)
{
    // - Массив линий союдиняющих вершины
    QVector<QLine> Lines = {QLine(200, 75, 350, 75),
                            QLine(100, 275, 250, 275),
                            QLine(300, 275, 450, 275),
                            QLine(75, 250, 175, 100),
                            QLine(275, 250, 375, 100),
                            QLine(475, 250, 375, 100),
                            QLine(275, 250, 175, 100)};

    // - Массив вершин графа
    QVector<QPoint> Vertexes = {QPoint(150+25, 50+25),
                                QPoint(350+25, 50+25),
                                QPoint(50+25, 250+25),
                                QPoint(250+25, 250+25),
                                QPoint(450+25, 250+25)};

    // - Массив названий вершин
    QVector<QString> VertexNames = {"a",
                                   "e",
                                   "b",
                                   "c",
                                   "d"};

    // - Веса рёбер
    QVector<QString> LineWeight = {"1",
                                  "3",
                                  "4",
                                  "6",
                                  "7",
                                  "5",
                                  "2"};

    // - Кисть для рисования основная
    QPen pen(Qt::black, 2, Qt::SolidLine);

    // - Кисть для выделения
    QPen pen_red(Qt::red, 4, Qt::SolidLine);

    // - Рисуем вершины
    painter -> setPen(pen);
    for(int i = 0; i < Vertexes.size(); i++)
    {
        painter -> drawEllipse(Vertexes[i], 25, 25);
        painter -> drawText(Vertexes[i], VertexNames[i]);
    }

    painter -> drawLines(Lines);

    // - Рисуем веса рёбер
    painter -> drawText(QPoint(275, 70), "1");
    painter -> drawText(QPoint(100, 175), "3");
    painter -> drawText(QPoint(230, 175), "4");
    painter -> drawText(QPoint(300, 175), "6");
    painter -> drawText(QPoint(450, 175), "7");
    painter -> drawText(QPoint(175, 270), "5");
    painter -> drawText(QPoint(375, 270), "2");

    painter -> setPen(pen_red);
    if(PageNumber >= 0)
    {
        painter -> drawEllipse(Vertexes[0], 25, 25);

    }

    if(PageNumber >= 1)
    {
        painter -> drawLine(Lines[0]);
        painter -> drawLine(Lines[3]);
        painter -> drawLine(Lines[6]);
    }

    if(PageNumber >= 2)
    {
        painter -> drawEllipse(Vertexes[1], 25, 25);
        painter -> drawLine(Lines[5]);
    }

    if(PageNumber >= 3)
    {
        painter -> setPen(QPen(Qt::gray, 4, Qt::SolidLine));
        painter -> drawLine(Lines[5]);
        painter -> drawLine(Lines[1]);
        painter -> drawLine(Lines[4]);
        painter -> drawText(QPoint(300, 175), "6");
        painter -> drawText(QPoint(450, 175), "7");
        painter -> drawText(QPoint(175, 270), "5");
        painter -> setPen(pen_red);

        painter -> drawEllipse(Vertexes[2], 25, 25);
        painter -> drawEllipse(Vertexes[3], 25, 25);
        painter -> drawEllipse(Vertexes[4], 25, 25);
        painter -> drawLine(Lines[2]);
    }
}

void DemonstrationWindow::call_paint()
{
    repaint();
}

void DemonstrationWindow::on_nextQuestion_clicked()
{
    PageNumber++;
    if(PageNumber < 4)
        ui -> DescriptionTextBox -> setText(Messages[PageNumber]);
    call_paint();
}
