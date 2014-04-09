#include "headband.h"

/*
 *  Auteur: SimonTPT
 **/

using namespace std;

Headband::Headband(QWidget* parent, QString title): QWidget(parent)
{
    //Taille et arrière plan
    setFixedWidth(parent->width());
    setFixedHeight(parent->height()/7);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);

    //Layout en grille
    QGridLayout* gL = new QGridLayout();

    //Label contenat le titre (entrees,plats,...)
    this->title = title;
    QLabel* top = new QLabel(title + " : ",this);
    top->setAlignment(Qt::AlignHCenter);

    //Bouton de filtre
    QLabel* filterLabel = new QLabel("Filtre :",this);
    filter = new QComboBox(this);
    filter->addItem("Aucun");
    filter->addItem("Nouveautés");
    filter->addItem("Spécialités");
    filter->addItem("Petits prix");

    //Boutons pour ajouter/retirer bandeau
    plus = new QPushButton("+",this);
    plus->setFixedWidth(plus->sizeHint().height());
    minus = new QPushButton("-",this);
    minus->setFixedWidth(minus->sizeHint().height());
    QHBoxLayout* hbl = new QHBoxLayout();
    hbl->addWidget(plus);
    hbl->addWidget(minus);

    //QWidget contenant les flèches
    arrowL = new Arrow(this,"arrowL");
    arrowR = new Arrow(this,"arrowR");

    //Au milieu on a une scrollArea contenant tous les headbandItem
    scrollArea = new HeadbandScrollArea(this);
    centralWidget = new HeadbandWidget(scrollArea);
    scrollArea->setWidget(centralWidget);

    /*QWidget* w1 = new QWidget(centralWidget);
    w1->setAttribute(Qt::WA_TransparentForMouseEvents);
    w1->setPalette(QPalette(Qt::green));
    w1->setAutoFillBackground(true);
    w1->setFixedWidth(300);

    centralWidget->addHeadbandItem(w1);*/

    //Ajout des widget au layout
    gL->addWidget(filterLabel,0,0,1,1);
    gL->addWidget(filter,0,1,1,2);
    gL->addWidget(top,0,1,1,12);
    gL->addLayout(hbl,0,12,1,2);
    gL->addWidget(arrowL,1,0,3,1);
    gL->addWidget(scrollArea,1,1,3,12);
    gL->addWidget(arrowR,1,13,3,1);

    this->setLayout(gL);
    this->show();
    QObject::connect(arrowL,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    QObject::connect(arrowR,SIGNAL(click(QString)),scrollArea,SLOT(arrowClicked(QString)));
    QObject::connect(centralWidget,SIGNAL(scrolling(int)),this,SLOT(applyScroll(int)));
}

void Headband::applyScroll(int dx)
{
    scrollArea->scrollContent(dx,0);
}

/*void Headband::mouseMoveEvent(QMouseEvent *event)
{
    //Scroll plus ou moins rapide suivant la position de la souris

    float x = event->pos().x();
    float y = event->pos().y();
    cout << "band" <<x << endl;
    cout << y << endl;


}*/
