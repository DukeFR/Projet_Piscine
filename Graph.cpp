#include "graph.h"
#include <fstream>
#include <iostream>

graphe::graphe(std::string nomFichier){
    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    int x;
    int y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.push_back({new Sommet{id,x,y}});
    }

    int taille;
    ifs >> taille;
    std::cout << "taille" << taille << "ordre" << ordre <<std::endl;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");
    int arrivee;
    int depart;
    int idA;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifs>>idA; if(ifs.fail()) throw std::runtime_error("Probleme lecture poids");
        ifs>>depart; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifs>>arrivee; if(ifs.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        m_arrete.push_back({new Arrete{m_sommets[depart],m_sommets[arrivee],idA,1,1}});
       // (m_sommets.find(depart))->second->ajouterVoisin((m_sommets.find(arrivee))->second);
    }
}



void graphe::afficher() const
{
    for(const auto& elem : m_sommets)
    {
        elem->afficherData();
    }

    for(const auto& v : m_arrete)
    {
        v->afficherArrete();
    }
}
