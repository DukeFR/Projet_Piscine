#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "Arete.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


class graphe
{
    public:
        graphe(std::string);
        //~graphe();
        void afficher() const;

    protected:

    private:
        /// Le réseau est constitué d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::vector<Arete*> m_arete;

};



#endif // GRAPH_H_INCLUDED
