#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include "Sommet.h"
#include <iostream>

class Arete
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Arete(Sommet*,Sommet*,int,int,int);
        //~Arrete();
        void afficherArete() const;
        Sommet* getDepart();
        Sommet* getArrivee();
        int getPoids();

    protected:

    private:
        Sommet* depart;
        Sommet* arrivee;
        int m_id;
        int m_poids1;
        int m_poids2;

};

#endif // ARETE_H_INCLUDED
