#include "Equipe.h"


Equipe::Equipe(std::string name,std::vector<std::string> n, std::vector<int> e, std::vector<int> p,std::vector<int> r) :m_nom{name}, m_cycliste{n}, m_endurance{e}, m_point{e},m_marque{false},m_poids{0},m_recuperation{r}
{

}

int Equipe::selection(Equipe Fdjv,Equipe Prof,Equipe Pro,Equipe Dev)
{
    int choix;
    system("cls");
    std::cout <<"-----------------Selectionnez votre equipe-----------------" << std::endl;
    for(int i=0; i<2; i++)
    {
        std::cout<<std::endl;
    }
    std::cout << "1. " <<std::endl;
    affichage(Fdjv);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "2. " <<std::endl;
    affichage(Prof);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "3. " <<std::endl;
    affichage(Pro);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "4. " <<std::endl;
    affichage(Dev);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "1. Equipe FDJV" << std::endl;
    std::cout << "2. Equipe Prof" << std::endl;
    std::cout << "3. Equipe Pro" << std::endl;
    std::cout << "4. Equipe Dev" << std::endl;
    do
    {
        std::cin >>choix;
    }
    while (choix!=1 && choix!=2 && choix!=3 && choix!=4);
    if(choix==1)
    {
        return 1;
    }
    if(choix==2)
    {
        return 2;
    }
    if(choix==3)
    {
        return 3;
    }
    if(choix==4)
    {
        return 4;
    }
    return 1;

}

void Equipe::affichage(Equipe E)
{
    std::cout << E.m_nom << ": "<< std::endl;
    for(unsigned int i=0; i<E.m_cycliste.size(); i++)
    {
        std::cout << E.m_cycliste[i] << " " << "Endurance: " << E.m_endurance[i] << std::endl;
    }
}

void Equipe::setMarque()
{
    m_marque=true;
}

bool Equipe::getMarque()
{
    return m_marque;
}

void Equipe::setEndurance(int valeur, int i)
{
    m_endurance[i]=m_endurance[i]-valeur;
}

void Equipe::course(graphe g)
{
    BITMAP*buffer=create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP*track=create_bitmap(SCREEN_W,SCREEN_H);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    g.placerPoints();
    g.dessinerGraphePoids();
    int nom=0;
    int choix=10;
    int c=0;
    std::set<int> choixP;
    int taille=g.getM_Sommets().size()-1;
    std::cout << "t: " << taille << std::endl;
    for(int i=0; i<this->m_cycliste.size();i++)
    {
        for(const auto& elem : g.getM_Sommets())
        {
            if(elem->getm_id()==nom)
            {
                elem->setMarque();
            }
        }
        do
        {
            for(const auto& v : g.getM_arrete())
            {
                if(((v->getDepart()->getMarque()==true)&&(v->getArrivee()->getMarque()==false))||((v->getDepart()->getMarque()==false)&&(v->getArrivee()->getMarque()==true)))
                {
                    if(v->getArrivee()->getMarque()==false)
                    {
                        std::cout << "Aller vers le sommet: " << v->getArrivee()->getm_id() << " en passant par l'arete: " << v->getm_id()<< std::endl;
                        choixP.insert(v->getm_id());
                    }
                    if(v->getDepart()->getMarque()==false)
                    {
                        std::cout << "Aller vers le sommet:  " << v->getDepart()->getm_id() << " en passant par l'arete: " << v->getm_id()<< std::endl;
                        choixP.insert(v->getm_id());
                    }
                }
            }
            do
            {
                std::cout << "Saisissez votre choix de vecteur: " << std::endl;
                std::cin >> choix;
            }
            while(choixP.find(choix)==choixP.end());
            choixP.clear();
            if(g.getM_arrete()[choix]->getDepart()->getMarque()==true)
            {
                g.getM_arrete()[choix]->getArrivee()->setMarque();
                g.getM_arrete()[choix]->getDepart()->setClear();
                std::cout <<"S:" << g.getM_arrete()[choix]->getArrivee()->getm_id()<< std::endl;
                std::cout <<"F:" << g.getM_Sommets()[taille]->getm_id() << std::endl;
                if(g.getM_arrete()[choix]->getArrivee()->getm_id()==g.getM_Sommets()[taille]->getm_id())
                {
                    c=1;
                }
            }
            else
            {
                g.getM_arrete()[choix]->getDepart()->setMarque();
                g.getM_arrete()[choix]->getArrivee()->setClear();
                std::cout <<"S:" << g.getM_arrete()[choix]->getDepart()->getm_id() << std::endl;
                std::cout <<"F:" << g.getM_Sommets()[taille]->getm_id() << std::endl;
                if(g.getM_arrete()[choix]->getDepart()==g.getM_Sommets()[taille])
                {
                    c=1;
                }
            }
            std::cout << "c: " << c << std::endl;
        }
        while(c==0);
    }
}
