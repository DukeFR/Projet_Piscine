#include "Graph.h"
#include <fstream>
#include <iostream>
#include "allegro.h"
#include "math.h"
#include "bitset"
#include <queue>
#include <unordered_set>
#include <vector>
#include <list>
#include "time.h"
#include "algorithm"

graphe::graphe(std::string nomFichierSommets, std::string nomFichierPoids)
{
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
    for(size_t i =0; i<this->getM_Sommets().size();i++)
    {
       this->getM_Sommets()[i]->setClear();
    }
    int minimum=99;
    int nom=0;
    unsigned int ajout=0;
    Sommet*temporaireD = 0;
    Sommet*temporaireA = 0;
    Arrete* Temporaire;
    int p1 = 0;
    int p2 = 0;
    int id = 0;

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


 int graphe::binaire(const int nombre, int choix)

{
    install_mouse();
    show_mouse(screen);
    int men=0;
    int maximum= this->getM_arrete().size();
    //float poids;
    maximum=pow(2,maximum);
    std::vector<std::string> b;
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
    if(choix==1)
    {men=Acycle(b,nombre);}
    if(choix==0)
    {std::cout << "ok" << std::endl;
        men=Bitograph(b,nombre);
    }

    return men;
}

int graphe::Acycle(std::vector<std::string> b,int nombre)
{
    unsigned int a=0;
    std::vector<std::string> collecteur;
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
    int men=Bitograph(collecteur,nombre);
    return men;
}


int graphe::Bitograph(std::vector<std::string> collecteur, int nombre)
{
    std::vector<Sommet*> s;
    std::vector <Arrete*>ar;
    std::vector<graphe> liste;
    ar.clear();
    s.clear();
    for(unsigned int i=0;i<collecteur.size();i++)
    {
        for(int j=nombre-1;j>=0;j--)
        {
            if(collecteur[i][nombre-j-1]=='1')
            {
                s.push_back(m_arrete[(j)]->getArrivee());
                s.push_back(m_arrete[(j)]->getDepart());
                ar.push_back(m_arrete[j]);
                sort(s.begin(),s.end());
                sort(ar.begin(),ar.end());
                s.erase( unique( s.begin(), s.end() ), s.end() ); ///Ici on retire les doublons
            }
        }
        //std::cout << "----------------------------------------------------------------------------------------------------------"<< std::endl;
        //for(int k=0;k<ar.size();k++)
        //{
            //ar[k]->afficherArrete();
        //}
        if(m_sommets.size()==s.size())

        {liste.push_back(graphe(m_sommets,ar));}
        ar.clear();
        s.clear();
    }
    int men=bfs(liste);
    return men;
}

int graphe::bfs(std::vector<graphe> liste)
{
    std::vector<graphe> lst;
    for(size_t i=0;i<liste.size();i++)
    {
        if(parcoursBFS(liste[i])==true)
        {
            lst.push_back(liste[i]);
        }
    }
    int poids1=0;
    int poids2=0;
    for(size_t i=0;i<lst.size();i++)
    {
        for(size_t j=0;j<lst[i].getM_arrete().size();j++)
        {
            poids1=poids1+lst[i].getM_arrete()[j]->getPoids1();
            poids2=poids2+lst[i].getM_arrete()[j]->getPoids2();
        }
        //liste[i]->afficher();
        poids1=0;
        poids2=0;
    }
    //std::cout << "On valide" << std::endl;
    //liste[0]->afficher();

    std::cout << "Fin 3" << std::endl;
    int men=affichagePareto(lst);
    return men;

}

int graphe::affichagePareto(std::vector<graphe> P)
{
    install_mouse();
    show_mouse(screen);
   std::vector<int> selection;
    for(size_t i=0;i<P.size();i++)
    {
        selection.push_back(6);
    }
    std::vector<int> sp1;
    std::vector<int> sp2;
    std::cout << "Fin 4" << std::endl;
    int poids1=0;
    int poids2=0;
    int couleur=makecol(255,0,0);
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_bitmap(buffer);
    for(size_t i=0;i<P.size();i++)
    {
        for(size_t j=0;j<P[i].getM_arrete().size();j++)
        {
            poids1=poids1+P[i].getM_arrete()[j]->getPoids1();
            poids2=poids2+P[i].getM_arrete()[j]->getPoids2();

        }
        sp1.push_back(poids1);
        sp2.push_back(poids2);
        poids1=0;
        poids2=0;
    }
    std::cout <<"c: "<< sp1.size() << std::endl;
    for(size_t i=0;i<sp1.size();i++)
    {
        for(size_t j=0;j<sp1.size();j++)
        {
            if((sp1[i]>sp1[j])&&(sp2[i]>sp2[j]))
            {
                selection[i]=10;
                j=sp1.size();
            }
        }
    }

    line(buffer,300,225,300,500,couleur);
    line(buffer,300,225,280,245,couleur);
    line(buffer,300,225,320,245,couleur);
    textprintf_ex(buffer,font,220,225,couleur,-1,"cout 2");

    line(buffer,300,500,575,500,couleur);
    line(buffer,575,500,555,480,couleur);
    line(buffer,575,500,555,520,couleur);
    textprintf_ex(buffer,font,555,530,couleur,-1,"cout 1");

    for(size_t i=0;i<selection.size();i++)
    {
        poids1=sp1[i];
        poids2=sp2[i];
        if(selection[i]==10)
        {
            couleur=makecol(255,0,0);
            circlefill(buffer,300+2*poids1,500-2*poids2,1,couleur);
        }
        if(selection[i]==6)
        {
            couleur=makecol(0,255,0);
            circlefill(buffer,300+2*poids1,500-2*poids2,2,couleur);
        }
    }

    std::cout << "Fin 5" << std::endl;
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    while (!key[KEY_SPACE])
    {
    }
    int men=1;
    return men;
}

void graphe::afficherPrim(std::vector<Arrete*> Prim)
{
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
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
    textprintf_ex(buffer,font,400,500,couleur,-1,"le poids total de l'arbre de cout 1 est %d",poids1);
    textprintf_ex(buffer,font,400,550,couleur,-1,"le poids total de l'arbre de cout 2 est %d",poids2);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void graphe::dessinerGraphePoids()
{
    int couleur=makecol(255,0,0);
    int c=makecol(100,100,255);
    int co=makecol(125,125,125);
    Sommet* D;
    Sommet* A;

    for(const auto& elem : m_sommets) ///dessiner les sommets
    {
        circlefill(screen,elem->getm_x()+350,elem->getm_y(),10,couleur);
        textprintf_ex(screen,font,elem->getm_x()+335,elem->getm_y()-15,co,-1,"%d",elem->getm_id());
    }
    for(const auto& v : m_arrete) ///dessiner les aretes
    {
        D=v->getDepart();
        A=v->getArrivee();
        line(screen,D->getm_x()+350,D->getm_y(),A->getm_x()+350,A->getm_y(),couleur);
        if(D->getm_x()==A->getm_x())
        {
        int distance1=A->getm_y();
        int distance2=D->getm_y();
        int distance=(distance1+distance2)/2;
        textprintf_ex(screen,font,D->getm_x()+360,distance,c,-1,"%d;%d",v->getPoids1(),v->getPoids2());
        }

        if(D->getm_y()==A->getm_y())
        {
        int distance1=A->getm_x();
        int distance2=D->getm_x();
        int distance=(distance1+distance2)/2;
        textprintf_ex(screen,font,distance+350,D->getm_y()-10,c,-1,"%d;%d",v->getPoids1(),v->getPoids2());
        }

        if((D->getm_y()!=A->getm_y())&&(D->getm_x()!=A->getm_x()))
        {
                int distance1=A->getm_x();
                int distance2=D->getm_x();
                int distancex=(distance1+distance2)/2;
                int distance3=A->getm_y();
                int distance4=D->getm_y();
                int distancey=(distance3+distance4)/2;
             textprintf_ex(screen,font,distancex+350,distancey,c,-1,"%d;%d",v->getPoids1(),v->getPoids2());

        }
    }
}

void graphe::placerPoints()
{
    //BITMAP*page;
    int couleur=makecol(255,0,0);
    int c=makecol(100,100,255);
    int co=makecol(125,125,125);
    Sommet* D;
    Sommet* A;
    for(const auto& elem : m_sommets) ///dessiner les sommets
    {
        circlefill(screen,elem->getm_x()-50,elem->getm_y(),10,couleur);
        textprintf_ex(screen,font,elem->getm_x()-65,elem->getm_y()-15,co,-1,"%d",elem->getm_id());
    }
    for(const auto& v : m_arrete) ///dessiner les aretes
    {
        D=v->getDepart();
        A=v->getArrivee();
        line(screen,D->getm_x()-50,D->getm_y(),A->getm_x()-50,A->getm_y(),couleur);
        if(D->getm_x()==A->getm_x())
        {
        int distance1=A->getm_y();
        int distance2=D->getm_y();
        int distance=(distance1+distance2)/2;
        textprintf_ex(screen,font,D->getm_x()-70,distance,c,-1,"%d",v->getm_id());
        }

        if(D->getm_y()==A->getm_y())
        {
        int distance1=A->getm_x();
        int distance2=D->getm_x();
        int distance=(distance1+distance2)/2;
        textprintf_ex(screen,font,distance-50,D->getm_y()-10,c,-1,"%d",v->getm_id());
        }

        if((D->getm_y()!=A->getm_y())&&(D->getm_x()!=A->getm_x()))
        {
                int distance1=A->getm_x();
                int distance2=D->getm_x();
                int distancex=(distance1+distance2)/2;
                int distance3=A->getm_y();
                int distance4=D->getm_y();
                int distancey=(distance3+distance4)/2;
             textprintf_ex(screen,font,distancex-50,distancey,c,-1,"%d",v->getm_id());
        }
    }
}

void graphe::placerPointsMini()
{
    //BITMAP*page;
    int couleur=makecol(255,0,0);
    //int c=makecol(100,100,255);
    int co=makecol(125,125,125);
    Sommet* D;
    Sommet* A;
    for(const auto& elem : m_sommets) ///dessiner les sommets
    {
        circlefill(screen,(elem->getm_x())/2-15,(elem->getm_y())/2-15,5,couleur);
        textprintf_ex(screen,font,(elem->getm_x())/2-32,(elem->getm_y())/2-28,co,-1,"%d",elem->getm_id());
    }
    for(const auto& v : m_arrete) ///dessiner les aretes
    {
        D=v->getDepart();
        A=v->getArrivee();
        line(screen,(D->getm_x())/2-15,(D->getm_y())/2-15,(A->getm_x())/2-15,(A->getm_y())/2-15,couleur);
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

bool graphe::parcoursBFS(graphe g)
{
    int taille = g.getM_Sommets().size();
    int compteur = 1;
    bool retour = 0;
    std::queue<Sommet*> file;
    std::unordered_set<const Sommet*> marque;
    /*for(int i=0;i<g.getM_Sommets().size();i++)
    {
        std::cout<< g.getM_Sommets()[i]->getm_id() <<std::endl;
    }*/
    file.emplace(g.getM_Sommets().front());
    while(file.empty()!=1)
    {
        Sommet* s = file.front();
        file.pop();
        marque.insert(s);

        for(size_t i=0; i<g.getM_arrete().size(); i++)
        {
            if(marque.count(g.getM_arrete()[i]->getArrivee())==0)
            {
                if(s->getm_id() == g.getM_arrete()[i]->getDepart()->getm_id())
                {
                    file.push(g.getM_arrete()[i]->getArrivee());
                    compteur = compteur +1;
                    marque.insert(g.getM_arrete()[i]->getArrivee());
                }
            }
            if(marque.count(g.getM_arrete()[i]->getDepart())==0)
            {
                if(s->getm_id() == g.getM_arrete()[i]->getArrivee()->getm_id())
                {
                    file.push(g.getM_arrete()[i]->getDepart());
                    compteur = compteur +1;
                    marque.insert(g.getM_arrete()[i]->getDepart());
                }
            }
        }
    }

    if(compteur==taille)
    {
        //std::cout<<"ce graphe est connexe"<<std::endl;
        retour = true;
    }
    else
    {
        //std::cout << "ce graphe n'est pas connexe"<<std::endl;
        retour = false;
    }
    //std::cout << "compteur = "<<compteur<<std::endl;
    //std::cout << "taille = "<<taille<<std::endl;

    return retour;

}







std::unordered_map<Sommet*,float> graphe::dijkstra(Sommet* idep)
{
    float poidsT;
    std::unordered_set<Sommet*> marque;
    std::unordered_map<Sommet*,float> dist;
    Sommet*smin=nullptr;
    float dcard;
    float dmin=99999999999999;
    for(auto s: m_sommets)
    {
        dist[s]=10000000;
    }
    dist[idep]=0;
    //marque.insert(idep);
    std::cout <<"size: " << m_sommets.size() << std::endl;
    for(unsigned int r=0;r<m_sommets.size();r++)
    {
        std::cout << r << "eme etape" << std::endl;
        for(auto s : m_sommets)
        {
            std::cout << "s: " << s->getm_id() << std::endl;
            std::cout << "c :" << marque.count(s) << std::endl;
            if((!marque.count(s)) && (dist[s]<dmin))
            {
                std::cout << "M: " << s->getm_id() << std::endl;
                smin=s;
                dmin=dist[s];
                std::cout << "dmin: " << dmin << std::endl;
                std::cout << "smin: " << smin->getm_id() << std::endl;
            }
        }
    dmin=99999999999999;
    marque.insert(smin);
    ///POUR CHAQUE VOISINS NON MARQUE DE SMIN
    for(unsigned int i=0;i<m_arrete.size();i++)
    {
        if(((m_arrete[i]->getDepart()==smin)&&(marque.find(m_arrete[i]->getArrivee())==marque.end()))||((m_arrete[i]->getArrivee()==smin)&&(marque.find(m_arrete[i]->getDepart())==marque.end())))
        {
            std::cout<<"D: " << m_arrete[i]->getDepart()->getm_id() << std::endl;
            std::cout <<"A:" << m_arrete[i]->getArrivee()->getm_id() << std::endl;
            if(m_arrete[i]->getDepart()==smin)
            {

                dcard=dist[smin]+m_arrete[i]->getPoids2();
                std::cout << "distmin: " <<dist[smin] << std::endl;
                std::cout << "poids2: " << m_arrete[i]->getPoids2() << std::endl;
                std::cout << "distV: " <<dist[m_arrete[i]->getDepart()] << std::endl;
                std::cout << "dcard: " <<dcard << std::endl;
                if(dcard<dist[m_arrete[i]->getArrivee()])
                {
                    dist[m_arrete[i]->getArrivee()]=dcard;

                }
                dcard=0;
            }
            if(m_arrete[i]->getArrivee()==smin)
            {
                dcard=dist[smin]+m_arrete[i]->getPoids2();
                std::cout << "distmin: " <<dist[smin] << std::endl;
                std::cout << "poids2: " << m_arrete[i]->getPoids2() << std::endl;
                std::cout << "dcard: " <<dcard << std::endl;
                std::cout << "distV: " <<dist[m_arrete[i]->getDepart()] << std::endl;
                if(dcard<dist[m_arrete[i]->getDepart()])
                {
                    dist[m_arrete[i]->getDepart()]=dcard;

                }
                dcard=0;
            }
        }
    }
    }

    return dist;
}

