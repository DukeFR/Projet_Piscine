#ifndef EQUIPE_H_INCLUDED
#define EQUIPE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "allegro.h"
#include "Cycliste.h"
#include <set>
#include <algorithm>
#include <cstdlib>
#include <climits>

class Equipe
{
    public:
    Equipe(std::string name,std::vector<std::string> n, std::vector<int> e, std::vector<int> p, std::vector<int> r,std::vector<int> poids);
    int selection(Equipe,Equipe,Equipe,Equipe);
    void affichage(Equipe E);
    void setMarque();
    bool getMarque();
    void setEndurance(int valeur,int i);
    void setPoids(float valeur, int i);
    void setPoints(int valeur, int i);
    void course(graphe g);
    void refill();
    std::unordered_map<std::string,std::string> selectionCourse(std::vector<std::string>tracks,std::vector<std::string>t1,std::vector<std::string>t2,std::vector<std::string>t4);
    void afficherCircuits(std::unordered_map<std::string,std::string> c);
    void ScoreEtape(Equipe* Prof, Equipe* Pro, Equipe* Dev);
    void ScoreT(Equipe Prof, Equipe Pro, Equipe Dev);
    void AI(graphe g);


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
