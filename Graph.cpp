#include "graph.h"
#include <fstream>
#include <iostream>
#include "allegro.h"
#include <queue>
#include "math.h"
#include<unordered_set>

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

std::vector<Arrete*> graphe::prim(int choix)
{
    std::vector<Arrete*> Prim;
    int minimum=99;
    int nom=0;
    size_t ajout=0;
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


 std::vector<graphe> graphe::recursivite()
{
    /*int maximum= this->getM_arrete().size();
    std::vector<graphe> liste;
    std::string temp;
    for(int i=0;i<maximum;i++)
    {
        temp=temp+"0";
    }
    liste[0].
    for(int i=0;i<maximum;i++)
    {

    }*/
}

void graphe::afficherPrim(std::vector<Arrete*> Prim)
{
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    int couleur=makecol(0,255,0);
    for(size_t i=0;i<Prim.size();i++)
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

std::vector<Arrete*> graphe::getM_arrete()
{
    return m_arrete;
}

std::vector<Sommet*> graphe::getM_sommets()
{
    return m_sommets;
}

bool graphe::parcoursBFS(std::vector<Sommet*> sommets, std::vector<Arrete*> aretes)
{
    int taille = sommets.size();
    int compteur = 1;
    bool retour = 0;
    std::queue<Sommet*> file;
    std::unordered_set<const Sommet*> marque;

    file.push(sommets[0]);

    while(file.empty()!=1)
    {
        Sommet* s = file.front();
        file.pop();
        marque.insert(s);

        for(size_t i=0; i<aretes.size(); i++)
        {
            if(marque.count(aretes[i]->getArrivee())==0)
            {
                if(s->getm_id() == aretes[i]->getDepart()->getm_id())
                {
                    file.push(aretes[i]->getArrivee());
                    compteur = compteur +1;
                    marque.insert(aretes[i]->getArrivee());
                }
            }
        }
    }

    if(compteur==taille)
    {
        std::cout<<"ce graphe est connexe"<<std::endl;
        retour = true;
    }
    else
    {
        std::cout << "ce graphe n'est pas connexe"<<std::endl;
        retour = false;
    }
    std::cout << "compteur = "<<compteur<<std::endl;
    std::cout << "taille = "<<taille<<std::endl;

    return retour;

}

