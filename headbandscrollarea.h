#ifndef HEADBANDSCROLLAREA_H
#define HEADBANDSCROLLAREA_H
#include <QScrollArea>
#include <QScrollBar>
#include <iostream>
/*
 *  Classe représentnat la scrollArea au centre du bandeau, qui contient toutes
 *  les icones des plats, entrées,...
 *
 *  Auteur: SimonTPT
 **/

class HeadbandScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    HeadbandScrollArea(QWidget * parent);
    void scrollContent(int dx, int dy);

public slots:
    void arrowClicked(QString name);
};

#endif // HEADBANDSCROLLAREA_H
