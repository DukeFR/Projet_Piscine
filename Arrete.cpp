#include "Arrete.h"

#include <iostream>

Arrete::Arrete(Sommet* s1,Sommet* s2,int id,int p1,int p2):depart{s1},arrivee{s2},m_id{id},m_poids1{p1},m_poids2{p2}
{
}

void Arrete::afficherArrete() const
{
    std::cout<<"\n--------------------------------------------\n"<<std::endl;
    std::cout<<"Arete numero: "<<m_id<<" "<<std::endl<<std::endl;

    depart->afficherData();
    arrivee->afficherData();
    std::cout<<" "<<std::endl;

    std::cout<<"poids1: "<<m_poids1<<" "<<std::endl;
    std::cout<<"poids2: "<<m_poids2<<" "<<std::endl;
}

Sommet* Arrete::getDepart()
{
    return depart;
}

Sommet* Arrete::getArrivee()
{
    return arrivee;
}

int Arrete::getPoids()
{
    return m_poids1;
}
