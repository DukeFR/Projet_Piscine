#include "Sommet.h"

#include <iostream>

Sommet::Sommet(int id,int x1,int y1):m_id{id},marque{false},marqueD{false},m_x{x1},m_y{y1}
{
}

 void Sommet::afficherData() const{
     std::cout<<"Numero: "<<m_id<<" / "<<" Marque: "<<marque<<" / "<<"X: "<<m_x<<" / "<<" Y: "<<m_y<<std::endl;
 }

 bool Sommet::getMarque()
 {
     return marque;
 }

 void Sommet::setMarque()
 {
     marque=true;
 }

 void Sommet::setClear()
 {
     marque=false;
 }

 int Sommet::getm_x()
 {
     return m_x;
 }

int Sommet::getm_y()
{
    return m_y;
}

int Sommet::getm_id()
{
    return m_id;
}

