#include "Sommet.h"

#include <iostream>

Sommet::Sommet(int id,int x1,int y1):m_id{id},marque{false},m_x{x1},m_y{y1}
{
}

 void Sommet::afficherData() const{
     std::cout<<"id: "<<m_id<<" "<<"M: "<<marque<<" "<<"x"<<m_x<<" "<<"y: "<<m_y<<std::endl;
 }

 bool Sommet::getMarque()
 {
     return marque;
 }

 void Sommet::setMarque()
 {
     marque=true;
 }


