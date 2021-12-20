#include "theory.h"

Theory::Theory()
{

}

void Theory::ReadFile(QString Path)
{
    QWebEngineView *view = new QWebEngineView();
    view -> load(QUrl(Path));
}
