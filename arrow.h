#ifndef ARROW_H
#define ARROW_H
#include <QWidget>
#include <QString>
#include <QPainter>
#include <QStyleOption>
#include <QMouseEvent>
/*
 *  Classe Repésentant un flèche
 *
 *  Auteur: SimonTPT
 **/


class Arrow: public QWidget
{
    Q_OBJECT
private :
    QString name;

public:
    Arrow(QWidget * parent, QString name):QWidget(parent)
    {
        this->name = name;
        setStyleSheet(" border-image: url(:/Images/images/"+name+".png) ");
    }

    inline void mouseReleaseEvent(QMouseEvent *)
    {
        emit click(name);
    }
    inline void paintEvent(QPaintEvent *)
    {
      QStyleOption o;
      o.initFrom(this);
      QPainter p(this);
      style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
    }

signals:
    //Les fleches permettent d'atteindre les extrémités de la liste
    //Signaux à destination de headbandScrollArea
    void click(QString name);

};

#endif // ARROW_H
