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
        graphe(std::string);
        //~graphe();
        void afficher() const;

    protected:

    private:
        /// Le r�seau est constitu� d'une collection de sommets
        std::vector<Sommet*> m_sommets;//stock�e dans une map (cl�=id du sommet, valeur= pointeur sur le sommet)
        std::vector<Arrete*> m_arrete;

};



#endif // GRAPH_H_INCLUDED
