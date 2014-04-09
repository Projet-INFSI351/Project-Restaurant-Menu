#ifndef HEADBAND_H
#define HEADBAND_H
#include <QImage>
#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QMouseEvent>
#include <QComboBox>
#include "headbandwidget.h"
#include "headbandscrollarea.h"
#include "arrow.h"

/*
 *  Classe Repésentant le bandeau entier (conteneur)
 *
 *  Auteur: SimonTPT
 **/


class Headband: public QWidget
{
    Q_OBJECT

public:
    Headband(QWidget *parent, QString title);
    //void mouseMoveEvent(QMouseEvent *event);

private:
    QString title;
    Arrow* arrowL;
    Arrow* arrowR;
    HeadbandScrollArea* scrollArea;
    HeadbandWidget *centralWidget;
    QComboBox *filter;
    QPushButton *plus;
    QPushButton *minus;
    //vector<headbandItem> headbandList

public slots:
    void applyScroll(int dx);
};

#endif // HEADBAND_H
