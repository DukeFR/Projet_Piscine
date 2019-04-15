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
        /// Le r�seau est constitu� d'une collection de sommets
        std::unordered_map<int,Sommet*> m_sommets;//stock�e dans une map (cl�=id du sommet, valeur= pointeur sur le sommet)
        std::vector<Arete*> m_arete;

};



#endif // GRAPH_H_INCLUDED
