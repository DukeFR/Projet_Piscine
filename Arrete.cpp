#include "Arrete.h"

#include <iostream>

Arrete::Arrete(Sommet* s1,Sommet* s2,int id,float p1,float p2):depart{s1},arrivee{s2},m_id{id},m_poids1{p1},m_poids2{p2}
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

int Arrete::getm_id()
{
    return m_id;
}

int Arrete::getPoids2()
{
    return m_poids2;
}

int Arrete::getPoids1()
{
    return m_poids1;
}
