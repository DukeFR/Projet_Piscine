#include "Arete.h"

#include <iostream>

Arete::Arete(Sommet* s1,Sommet* s2,int id,int p1,int p2):depart{s1},arrivee{s2},m_id{id},m_poids1{p1},m_poids2{p2}
{
}

void Arete::afficherArete() const
{
    depart->afficherData();
    arrivee->afficherData();
    std::cout<<"--------------------------------------------"<<std::endl;
    std::cout<<"id:"<<m_id<<" "<<std::endl;
    std::cout<<"poids1:"<<m_poids1<<" "<<std::endl;
    std::cout<<"poids2"<<m_poids2<<" "<<std::endl;
}

Sommet* Arete::getDepart()
{
    return depart;
}

Sommet* Arete::getArrivee()
{
    return arrivee;
}

int Arete::getPoids()
{
    return m_poids1;
}
