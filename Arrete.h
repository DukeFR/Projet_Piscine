#ifndef ARRETE_H_INCLUDED
#define ARRETE_H_INCLUDED
#include "Sommet.h"
#include <iostream>

class Arrete
{
    public:
        ///constructeur qui re�oit en params les donn�es du sommet
        Arrete(Sommet*,Sommet*,int,float,float);
        //~Arrete();
        void afficherArrete() const;
        Sommet* getDepart();
        Sommet* getArrivee();
        int getm_id();
        int getPoids1();
        int getPoids2();

    protected:

    private:
        Sommet* depart;
        Sommet* arrivee;
        int m_id;
        float m_poids1;
        float m_poids2;

};

#endif // ARRETE_H_INCLUDED
