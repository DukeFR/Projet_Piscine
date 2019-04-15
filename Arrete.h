#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED
#include "Sommet.h"
#include <iostream>

class Arrete
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Arrete(Sommet*,Sommet*,int,int,int);
        //~Arrete();
        void afficherArrete() const;
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

#endif // ARRETE_H_INCLUDED
