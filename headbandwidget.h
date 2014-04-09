#ifndef HEADBANDWIDGET_H
#define HEADBANDWIDGET_H
#include <QWidget>
#include <QHBoxLayout>
#include <iostream>
#include <QMouseEvent>
/*
 *  Classe conteneur des icones de plats. Elle est ajoutées dans la scrollArea
 *
 *  Auteur: SimonTPT
 **/

class HeadbandWidget : public QWidget
{
    Q_OBJECT
public:
    HeadbandWidget(QWidget* parent);
    void addHeadbandItem(QWidget *item);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);

private:
    QPoint init;
    QPoint pos;
    QHBoxLayout* bL;
    //Multiplicateur pour la vitesse du scrolling
    static const int V = 3;
    int dx;

signals:
    void scrolling(int dx);
};

#endif // HEADBANDWIDGET_H
