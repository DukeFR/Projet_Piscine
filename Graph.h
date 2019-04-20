
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "Arrete.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


class graphe
{
    public:
        graphe(std::string, std::string);
        graphe(std::vector<Sommet*>,std::vector<Arrete*>);
        //~graphe();
        void afficher() const;
        void placerPoints();
        void placerPointsMini();
        void dessinerGraphePoids();
        std::vector<Arrete*> prim(int choix);
        void afficherPrim(std::vector<Arrete*> Prim);
        bool parcoursBFS(graphe g);
        std::vector<Arrete*> getM_arrete();
        std::vector<Sommet*> getM_Sommets();
        int binaire(int,int);
        int Acycle(std::vector<std::string> b, int nombre);
        int affichagePareto(std::vector<graphe> P);
        int Bitograph(std::vector<std::string> collecteur, int nombre);
        int bfs (std::vector<graphe> liste);
        std::unordered_map<Sommet*,float> dijkstra(Sommet* idep);

    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::vector<Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::vector<Arrete*> m_arrete;

};



#endif // GRAPH_H_INCLUDED

