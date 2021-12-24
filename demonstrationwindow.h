#ifndef DEMONSTRATIONWINDOW_H
#define DEMONSTRATIONWINDOW_H

#include <QDialog>
#include <QPainter>
#include <QPen>
#include <QGraphicsView>

namespace Ui {
class DemonstrationWindow;
}

class DemonstrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DemonstrationWindow(QWidget *parent = nullptr);
    ~DemonstrationWindow();

private:
    Ui::DemonstrationWindow *ui;
    void paintEvent(QPaintEvent*);
    void DrawGraph(QPainter *painter);         // - Нарисовать граф
    QString Messages[4] = {"Извлечём из множества вершину a, так как её приоритет минимален.Рассмотрим смежные с ней вершины b, c, и e. Обновим их приоритеты, как веса соответствующих рёбер ab, ac и ae, которые будут добавлены в ответ.",
                          "Теперь минимальный приоритет у вершины е. Извлечём её и рассмотрим смежные с ней вершины a, c, и d. Изменим приоритет только у вершины d, так как приоритеты вершин a и с меньше, чем веса у соответствующих рёбер ea и ec, и установим приоритет вершины d равный весу ребра ed, которое будет добавлено в ответ.",
                          "После извлечения вершины b ничего не изменится, так как приоритеты вершин a и с меньше, чем веса у соответствующих рёбер ba и bc. Однако, после извлечения следующей вершины — c, будет обновлён приоритет у вершины d на более низкий (равный весу ребра cd) и в ответе ребро ed будет заменено на cd.",
                          "Далее будет рассмотрена следующая вершина — d, но ничего не изменится, так как приоритеты вершин e и с меньше, чем веса у соответствующих рёбер de и dc. После этого алгоритм завершит работу, так как в заданном множестве не останется вершин, которые не были бы рассмотрены"};
    int PageNumber = 0;                        // - Номер шага (демонстрации)
    void DrawExplanation();                    // - Выделить объясняемое
private slots:
    void call_paint();
    void on_nextQuestion_clicked();
};

#endif // DEMONSTRATIONWINDOW_H
