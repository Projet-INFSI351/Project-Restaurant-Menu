#include "headbandwidget.h"

/*
 *  Auteur: SimonTPT
 **/

using namespace std;

HeadbandWidget::HeadbandWidget(QWidget *parent):QWidget(parent)
{
    setPalette(QPalette(Qt::cyan));
    setAutoFillBackground(true);

    bL = new QHBoxLayout();

    QWidget* w = new QWidget(this);
    w->setAttribute(Qt::WA_TransparentForMouseEvents);
    w->setPalette(QPalette(Qt::red));
    w->setAutoFillBackground(true);
    w->setFixedWidth(500);

    QWidget* w1 = new QWidget(this);
    w1->setAttribute(Qt::WA_TransparentForMouseEvents);
    w1->setPalette(QPalette(Qt::green));
    w1->setAutoFillBackground(true);
    w1->setFixedWidth(300);

    //Ajout des widget au layout
    bL->addWidget(w);
    bL->addWidget(w1);

    this->setLayout(bL);
}

void HeadbandWidget::addHeadbandItem(QWidget* item)
{
    bL->addWidget(item);
}

void HeadbandWidget::mousePressEvent(QMouseEvent *event)
{
    init = event->pos();
    pos = init;
}
void HeadbandWidget::mouseMoveEvent(QMouseEvent *event)
{

    //cout << "initx " << pos.x() << endl;
    // cout << "posx " << init.x() << endl;
    pos = event->pos();
    int newdx = pos.x()-init.x();

    //Test se basant sur l'hypothèse d'un mouvement relativement continu.
    //On évite ainsi des erreurs du aux approximations des positions qui  sont nécéssairemetn des entiers
    //Si le dx précédent et le nouveau ont meme signe, alors on valide le mouvement.
    if(dx*newdx > 0)
    {
        //if()
            emit scrolling(V*newdx);
    }
    //cout << "bl " << bL->geometry().topLeft().x()  << endl;
    //cout << "this " << this->parentWidget()->geometry().topLeft().x() << endl;
    init = pos;
    dx = newdx;
}



