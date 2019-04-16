#include "graph.h"
#include <fstream>
#include <iostream>
#include "allegro.h"

graphe::graphe(std::string nomFichierSommets, std::string nomFichierPoids){
    std::ifstream ifsPoids{nomFichierPoids};
    std::ifstream ifsSommets{nomFichierSommets};

    if (!ifsSommets)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichierSommets );
    if (!ifsPoids)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichierPoids );
    int ordre;
    ifsSommets >> ordre;
    if ( ifsSommets.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    int x;
    int y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifsSommets>>id; if(ifsSommets.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifsSommets>>x; if(ifsSommets.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifsSommets>>y; if(ifsSommets.fail()) throw std::runtime_error("Probleme lecture données sommet");
        m_sommets.push_back({new Sommet{id,x,y}});
    }

    int taille;
    int nb_Poids;
    ifsSommets >> taille;
    ifsPoids >> taille;
    ifsPoids >> nb_Poids;

    std::cout << "taille : " << taille << " / ordre : " << ordre <<std::endl<<std::endl;
    if ( ifsSommets.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    int arrivee;
    int depart;
    float poids1;
    float poids2;
    int idA;
    //lecture des aretes
    for (int i=0; i<taille; ++i){
        //lecture des ids des deux extrémités
        ifsSommets>>idA; if(ifsSommets.fail()) throw std::runtime_error("Probleme lecture poids");
        ifsSommets>>depart; if(ifsSommets.fail()) throw std::runtime_error("Probleme lecture arete sommet 1");
        ifsSommets>>arrivee; if(ifsSommets.fail()) throw std::runtime_error("Probleme lecture arete sommet 2");
        ifsPoids>>idA; if(ifsSommets.fail()) throw std::runtime_error("Probleme lecture poids");
        ifsPoids>>poids1; if(ifsPoids.fail()) throw std::runtime_error("Probleme lecture poids n1");
        ifsPoids>>poids2; if(ifsPoids.fail()) throw std::runtime_error("Probleme lecture poids n2");
        m_arrete.push_back({new Arrete{m_sommets[depart],m_sommets[arrivee],idA,poids1,poids2}});
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

void graphe::prim()
{
    /*int minimum=99;
    int nom=0;
    int temp;
    int ajout;
    Sommet*temporaireD;
    Sommet*temporaireA;

    for(const auto& elem : m_sommets)
    {
      if(elem.get==nom)
      {
        elem.second->setMarque();
        prim.push_back(elem.first);
        ajout=ajout+1;
      }
    }
    nom="CE1";
    for(const auto& elem : m_sommets)
    {
      if(elem.first==nom)
      {
        elem.second->setMarque();
        prim.push_back(elem.first);
        ajout=ajout+1;
      }
    }
    nom="CE2";
    for(const auto& elem : m_sommets)
    {
      if(elem.first==nom)
      {
        elem.second->setMarque();
        prim.push_back(elem.first);
        ajout=ajout+1;
      }
    }

    do{
        for(const auto& v : m_arrete)
        {
            if(((v->getDepart()->getMarque()==true)&&(v->getArrivee()->getMarque()==false))||((v->getDepart()->getMarque()==false)&&(v->getArrivee()->getMarque()==true)))
            {
                if(minimum>v->getPoids())
                {
                    minimum=v->getPoids();
                    temporaireD=v->getDepart();
                    temporaireA=v->getArrivee();
                }
            }
       }
    if(temporaireA->getMarque()==false)
    {
        temporaireA->setMarque();
        prim.push_back(temporaireA->getID());
        ajout=ajout+1;
    }
    if(temporaireD->getMarque()==false)
    {
    temporaireD->setMarque();
    prim.push_back(temporaireD->getID());
    ajout=ajout+1;
    }
      minimum=99;

    }while(ajout<m_sommets.size()-1);*/
}




void graphe::placerPoints()
{
    //BITMAP*page;
    int couleur=makecol(255,0,0);
    Sommet* D;
    Sommet* A;
    for(const auto& elem : m_sommets)
    {
        circlefill(screen,elem->getm_x(),elem->getm_y(),10,couleur);
    }
    for(const auto& v : m_arrete)
    {
        D=v->getDepart();
        A=v->getArrivee();
        line(screen,D->getm_x(),D->getm_y(),A->getm_x(),A->getm_y(),couleur);
    }
}

