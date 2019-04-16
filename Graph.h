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
        //~graphe();
        void afficher() const;
        void placerPoints();
        std::vector<Arrete*> prim(int choix);
        void afficherPrim(std::vector<Arrete*> Prim);
        std::vector<Arrete*> getM_arrete();
        std::vector<graphe> recursivite();

    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::vector<Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::vector<Arrete*> m_arrete;

};



#endif // GRAPH_H_INCLUDED

