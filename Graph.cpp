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
        m_sommets.insert({id,new Sommet{id,x,y}});
        std::cout <<"ok"<< std::endl;
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
        m_arete.push_back({new Arete{m_sommets.find(depart)->second,m_sommets.find(arrivee)->second,idA,1,1}});
       // (m_sommets.find(depart))->second->ajouterVoisin((m_sommets.find(arrivee))->second);
    }
}



void graphe::afficher() const
{
    for(const auto& v : m_arete)
    {
        v->afficherArete();
    }
}
