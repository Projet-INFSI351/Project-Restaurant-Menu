#include "headbandscrollarea.h"

/*
 *  Auteur: SimonTPT
 **/

using namespace std;

HeadbandScrollArea::HeadbandScrollArea(QWidget *parent):QScrollArea(parent)
{
    //Rend les scrollbar invisibles
    horizontalScrollBar()->setStyleSheet("QScrollBar {height:0px;}");
    verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    //Le widget à l'intérieur prend ainsi toute la palce
    setWidgetResizable(true);
}

void HeadbandScrollArea::scrollContent(int dx, int dy)
{

    //cout<< (-widget()->width() +this->width())<< endl;

    //déplacement du widget à l'intérieur
    //On verifie qul'on ne se deplace pas d'une taille plus grande que le widget lui meme
    if( ((widget()->x() < 0 && (widget()->x()+dx) < 0)//évite de trop tirer vers la droite
         && widget()->x() > (-widget()->width() +this->width()) && (widget()->x()+dx) > (-widget()->width() +this->width()) )//evite de trop tier vers la gauche
            || (widget()->x() == 0 && dx < 0)//Si on est jsute à l'extrémité(droite ou gauche) on veut pouvoir repartir

            || (widget()->x() == (-widget()->width() +this->width()) && dx > 0) )
    {
        this->viewport()->scroll(dx,dy);
    }
}

void HeadbandScrollArea::arrowClicked(QString name)
{
//Déplacement a l'extrémité
    int dx = 0;
    if(name == "arrowL")
    {
        while(widget()->x() < 0)
        {
            dx ++;
            cout << dx << endl;
            while( (widget()->x()+dx) > 0)
            {
                dx --;
                cout << dx << endl;
            }
            this->viewport()->scroll(dx,0);
        }
    }
    else if (name == "arrowR")
    {
        while(widget()->x() > (-widget()->width() + this->width()))
        {
            dx ++;
            cout << dx << endl;
            while( (widget()->x()+dx) > (-widget()->width() +this->width()))
            {
                dx --;
                cout << dx << endl;
            }
            this->viewport()->scroll(dx,0);
        }
    }
}
