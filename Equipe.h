#ifndef EQUIPE_H_INCLUDED
#define EQUIPE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"

class Equipe
{
    public:
    Equipe(std::string name,std::vector<std::string> n, std::vector<int> e, std::vector<int> p, std::vector<int> r);
    void selection(Equipe,Equipe,Equipe,Equipe);
    void affichage(Equipe E);
    void setMarque();


    private:
        std::string m_nom;
        std::vector<std::string> m_cycliste;
        std::vector<int> m_endurance;
        std::vector<int> m_point;
        bool m_marque;
        std::vector<int> m_poids;
        std::vector<int> m_recuperation;
        std::vector<graphe*> m_g;
};



#endif // EQUIPE_H_INCLUDED
