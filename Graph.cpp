#include "Graph.h"
#include <fstream>
#include <iostream>
#include "allegro.h"
#include "math.h"
#include "bitset"
#include "vector"
#include "time.h"
#include "algorithm"

graphe::graphe(std::string nomFichierSommets, std::string nomFichierPoids){
    std::ifstream ifsPoids{nomFichierPoids};
    std::ifstream ifsSommets{nomFichierSommets};

    if (!ifsSommets)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichierSommets );
    if (!ifsPoids)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichierPoids );
    int ordre;
    ifsSommets >> ordre;
    if (ifsSommets.fail())
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
graphe::graphe(std::vector<Sommet*> s,std::vector<Arrete*> a): m_sommets{s}, m_arrete{a}
{

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
    unsigned int ajout=0;
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


 void graphe::binaire(const int nombre)
{
    int maximum= this->getM_arrete().size();
    maximum=pow(2,maximum);
    std::vector<graphe*> liste;
    std::vector<std::string> b;
    std::vector<std::string> collecteur;
    std::string temp;
    //std::cout << maximum << std::endl;
    for(int i=0;i<maximum;i++)
    {
        if(nombre==1)
        {temp=std::bitset<1>(i).to_string();}
        if(nombre==2)
        {temp=std::bitset<2>(i).to_string();}
        if(nombre==3)
        {temp=std::bitset<3>(i).to_string();}
        if(nombre==4)
        {temp=std::bitset<4>(i).to_string();}
        if(nombre==5)
        {temp=std::bitset<5>(i).to_string();}
        if(nombre==6)
        {temp=std::bitset<6>(i).to_string();}
        if(nombre==7)
        {temp=std::bitset<7>(i).to_string();}
        if(nombre==8)
        {temp=std::bitset<8>(i).to_string();}
        if(nombre==9)
        {temp=std::bitset<9>(i).to_string();}
        if(nombre==10)
        {temp=std::bitset<10>(i).to_string();}
        if(nombre==11)
        {temp=std::bitset<11>(i).to_string();}
        if(nombre==12)
        {temp=std::bitset<12>(i).to_string();}
        if(nombre==13)
        {temp=std::bitset<13>(i).to_string();}
        if(nombre==14)
        {temp=std::bitset<14>(i).to_string();}
        if(nombre==15)
        {temp=std::bitset<15>(i).to_string();}
        if(nombre==16)
        {temp=std::bitset<16>(i).to_string();}
        if(nombre==17)
        {temp=std::bitset<17>(i).to_string();}
        if(nombre==18)
        {temp=std::bitset<18>(i).to_string();}
        if(nombre==19)
        {temp=std::bitset<19>(i).to_string();}
        if(nombre==20)
        {temp=std::bitset<20>(i).to_string();}
        if(nombre==21)
        {temp=std::bitset<21>(i).to_string();}
        if(nombre==22)
        {temp=std::bitset<22>(i).to_string();}
        if(nombre==23)
        {temp=std::bitset<23>(i).to_string();}
        if(nombre==24)
        {temp=std::bitset<24>(i).to_string();}
        if(nombre==25)
        {temp=std::bitset<25>(i).to_string();}
        //std::cout << "temp: " << temp << std::endl;
        b.push_back(temp);
        //liste[i].GraphB(temp);
    }
    //std::cout << b.size()<<std::endl;
    std::cout << "Fin" << std::endl;
    unsigned int a=0;
    std::vector<Sommet*> s;
    std::vector <Arrete*>ar;
    for (unsigned int i=0;i<b.size();i++)
    {
        //std::cout <<"test:  " <<b[i][4] << std::endl;
        for(unsigned int j=0;j<b[i].size();j++)
        {
            if(b[i][j]=='1')
            {
                a=a+1;
            }

        }
        if(a==this->getM_Sommets().size()-1)
        {
            collecteur.push_back(b[i]);
        }
        a=0;
    }
    std::cout << "Fin2" << std::endl;
    std::cout << collecteur.size() << std::endl;
    for(unsigned int i=0;i<collecteur.size();i++)
    {
        //std::cout << "i: "<< i << " " << "b: " << collecteur[i] << std::endl;
        for(int j=nombre-1;j>=0;j--)
        {
            if(collecteur[i][nombre-j-1]=='1')
            {
                s.push_back(m_arrete[(j)]->getArrivee());
                s.push_back(m_arrete[(j)]->getDepart());
                ar.push_back(m_arrete[j]);
                sort(s.begin(),s.end());
                s.erase( unique( s.begin(), s.end() ), s.end() ); ///Ici on retire les doublons
            }
        }
        //std::cout << "----------------------------------------------------------------------------------------------------------"<< std::endl;
        //for(int k=0;k<ar.size();k++)
        //{
            //ar[k]->afficherArrete();
        //}
        std::cout << "ok" << m_sommets.size() << std::endl;
        std::cout << "ok1" << s.size() << std::endl;
        if(m_sommets.size()==s.size())
        {liste.push_back(new graphe(s,ar));}
        ar.clear();
        s.clear();
    }
    std::cout << "taille: " << liste.size()<< std::endl;
    int poids1=0;
    int poids2=0;
    for(int i=0;i<liste.size();i++)
    {
        for(int j=0;j<liste[i]->getM_arrete().size();j++)
        {
            poids1=poids1+liste[i]->getM_arrete()[j]->getPoids1();
            poids2=poids2+liste[i]->getM_arrete()[j]->getPoids2();
        }
        liste[i]->afficher();
        std::cout << "------" << "Poids1: " << poids1 << std::endl;
        std::cout <<" -------" << "Poids2: " << poids2 << std::endl;
        poids1=0;
        poids2=0;
    }
    //std::cout << "On valide" << std::endl;
    //liste[0]->afficher();
    BITMAP *buffer = create_bitmap(SCREEN_W,SCREEN_H);/// création du buffer
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    int compteur=0;
    do{
    if(key[KEY_ENTER])
    {
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        //liste[compteur]->afficher();
        //std::cout << "e" << std::endl;
        liste[compteur]->placerPoints();
        compteur=compteur+1;

    }
    }while(compteur!=liste.size());



}







void graphe::afficherPrim(std::vector<Arrete*> Prim)
{
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    int couleur=makecol(0,255,0);
    int poids1=0;
    int poids2=0;
    for(unsigned int i=0;i<Prim.size();i++)
    {
        circlefill(buffer,Prim[i]->getDepart()->getm_x(),Prim[i]->getDepart()->getm_y(),10,couleur);
        circlefill(buffer,Prim[i]->getArrivee()->getm_x(),Prim[i]->getArrivee()->getm_y(),10,couleur);
        line(buffer,Prim[i]->getDepart()->getm_x(),Prim[i]->getDepart()->getm_y(),Prim[i]->getArrivee()->getm_x(),Prim[i]->getArrivee()->getm_y(),couleur);
        poids1=poids1+Prim[i]->getPoids1();
        poids2=poids2+Prim[i]->getPoids2();
    }
    textprintf_ex(buffer,font,500,500,couleur,-1,"%d",poids1);
    textprintf_ex(buffer,font,500,550,couleur,-1,"%d",poids2);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
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

std::vector<Sommet*> graphe::getM_Sommets()
{
    return m_sommets;
}
