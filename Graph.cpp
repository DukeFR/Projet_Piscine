#include "graph.h"
#include <fstream>
#include <iostream>
#include "allegro.h"

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

std::vector<Arrete*> graphe::prim(int choix)
{
    std::vector<Arrete*> Prim;
    int minimum=99;
    int nom=0;
    int ajout=0;
    Sommet*temporaireD;
    Sommet*temporaireA;
    Arrete* Temporaire;
    int p1;
    int p2;
    int id;

    for(const auto& elem : m_sommets)
    {
      if(elem->getm_id()==nom)
      {
        elem->setMarque();
      }
    }


    do{
        for(const auto& v : m_arrete)
        {
            if(((v->getDepart()->getMarque()==true)&&(v->getArrivee()->getMarque()==false))||((v->getDepart()->getMarque()==false)&&(v->getArrivee()->getMarque()==true)))
            {
                if(choix==1)
                {if(minimum>v->getPoids1())
                {
                    minimum=v->getPoids1();
                    temporaireD=v->getDepart();
                    temporaireA=v->getArrivee();
                    id=v->getm_id();
                    p1=minimum;
                    p2=v->getPoids2();
                }
                }
                if(choix==2)
                {
                 if(minimum>v->getPoids2())
                {
                    minimum=v->getPoids2();
                    temporaireD=v->getDepart();
                    temporaireA=v->getArrivee();
                    id=v->getm_id();
                    p1=v->getPoids1();
                    p2=minimum;
                }
                }
            }
       }
    Temporaire=new Arrete(temporaireD,temporaireA,id,p1,p2);
    if(temporaireD->getMarque()==true)
    {
        temporaireA->setMarque();
    }
    if(temporaireA->getMarque()==true)
    {
        temporaireD->setMarque();
    }
    Prim.push_back(Temporaire);
    ajout=ajout+1;
    minimum=99;
    }while(ajout<m_sommets.size()-1);
    return Prim;
}
void graphe::afficherPrim(std::vector<Arrete*> Prim)
{
    int couleur=makecol(0,255,0);
    for(int i=0;i<Prim.size();i++)
    {
        circlefill(screen,Prim[i]->getDepart()->getm_x(),Prim[i]->getDepart()->getm_y(),10,couleur);
        circlefill(screen,Prim[i]->getArrivee()->getm_x(),Prim[i]->getArrivee()->getm_y(),10,couleur);
        line(screen,Prim[i]->getDepart()->getm_x(),Prim[i]->getDepart()->getm_y(),Prim[i]->getArrivee()->getm_x(),Prim[i]->getArrivee()->getm_y(),couleur);
    }
}



void graphe::placerPoints()
{
    //BITMAP*page;
    int couleur=makecol(255,0,0);
    int c=makecol(0,0,255);
    int co=makecol(125,125,125);
    Sommet* D;
    Sommet* A;
    for(const auto& elem : m_sommets)
    {
        circlefill(screen,elem->getm_x(),elem->getm_y(),10,couleur);
        textprintf_ex(screen,font,elem->getm_x()-15,elem->getm_y()-15,co,-1,"%d",elem->getm_id());
    }
    for(const auto& v : m_arrete)
    {
        D=v->getDepart();
        A=v->getArrivee();
        line(screen,D->getm_x(),D->getm_y(),A->getm_x(),A->getm_y(),couleur);

        if(D->getm_x()==A->getm_x())
        {
        int distance1=A->getm_y();
        int distance2=D->getm_y();
        int distance=(distance1+distance2)/2;
        textprintf_ex(screen,font,D->getm_x()-20,distance,c,-1,"%d",v->getm_id());
        }

        if(D->getm_y()==A->getm_y())
        {
        int distance1=A->getm_x();
        int distance2=D->getm_x();
        int distance=(distance1+distance2)/2;
        textprintf_ex(screen,font,distance,D->getm_y()-10,c,-1,"%d",v->getm_id());
        }

        if((D->getm_y()!=A->getm_y())&&(D->getm_x()!=A->getm_x()))
        {
                int distance1=A->getm_x();
                int distance2=D->getm_x();
                int distancex=(distance1+distance2)/2;
                int distance3=A->getm_y();
                int distance4=D->getm_y();
                int distancey=(distance3+distance4)/2;
             textprintf_ex(screen,font,distancex,distancey,c,-1,"%d",v->getm_id());

        }
    }
}

