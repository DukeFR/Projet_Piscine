#include "Equipe.h"


Equipe::Equipe(std::string name,std::vector<std::string> n, std::vector<int> e, std::vector<int> p,std::vector<int> r) :m_nom{name}, m_cycliste{n}, m_endurance{e}, m_point{p},m_marque{false},m_poids{0},m_recuperation{r}
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
    //BITMAP*track=create_bitmap(SCREEN_W,SCREEN_H);
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    g.placerPoints();
    g.dessinerGraphePoids();
    int nom=0;
    int choix=10;
    int c=0;
    std::set<int> choixP;
    int taille=g.getM_Sommets().size()-1;
    for(unsigned int i=0; i<this->m_cycliste.size();i++)
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
        system("cls");
        std::cout <<"Le cycliste est: " << this->m_cycliste[i] << std::endl;
        std::cout << "Endurance: " << this->m_endurance[i] << std::endl;
        std::cout << "Temps de parcours: " << this->m_poids[i] << std::endl;
        std::cout << "Nombre de points: " << this->m_point[i] << std::endl;
            for(const auto& v : g.getM_arrete())
            {
                if(((v->getDepart()->getMarque()==true)&&(v->getArrivee()->getMarque()==false))||((v->getDepart()->getMarque()==false)&&(v->getArrivee()->getMarque()==true)))
                {
                    if(v->getArrivee()->getMarque()==false)
                    {
                        std::cout << "Aller vers le sommet: " << v->getArrivee()->getm_id() << " en passant par l'arete: " << v->getm_id()<< " avec une perte d'endurance de: " << v->getPoids1() << std::endl;
                        choixP.insert(v->getm_id());
                    }
                    if(v->getDepart()->getMarque()==false)
                    {
                        std::cout << "Aller vers le sommet:  " << v->getDepart()->getm_id() << " en passant par l'arete: " << v->getm_id()<< " avec une perte d'endurance de: " << v->getPoids1()<< std::endl;
                        choixP.insert(v->getm_id());
                    }
                }
            }
            do
            {
                std::cout << "Saisissez votre choix d'arete: " << std::endl;
                std::cin >> choix;
            }
            while(choixP.find(choix)==choixP.end());
            choixP.clear();
            if(g.getM_arrete()[choix]->getDepart()->getMarque()==true)
            {
                g.getM_arrete()[choix]->getArrivee()->setMarque();
                g.getM_arrete()[choix]->getDepart()->setClear();
                this->m_endurance[i]=this->m_endurance[i]-g.getM_arrete()[choix]->getPoids1();
                this->m_poids[i]=this->m_poids[i]+g.getM_arrete()[choix]->getPoids1();
                if(g.getM_arrete()[choix]->getArrivee()->getm_id()==g.getM_Sommets()[taille]->getm_id())
                {
                    c=1;
                }
            }
            else
            {
                g.getM_arrete()[choix]->getDepart()->setMarque();
                g.getM_arrete()[choix]->getArrivee()->setClear();
                this->m_endurance[i]=this->m_endurance[i]-g.getM_arrete()[choix]->getPoids1();
                this->m_poids[i]=this->m_poids[i]+g.getM_arrete()[choix]->getPoids1();
                if(g.getM_arrete()[choix]->getDepart()==g.getM_Sommets()[taille])
                {
                    c=1;
                }
            }
        }
        while(c==0 || this->m_endurance[i]==0);
        if(this->m_endurance[i]==0)
        {
            this->m_poids[i]=9999;
        }
        c=0;
        for(const auto& v : g.getM_arrete())
        {
            v->getDepart()->setClear();
            v->getArrivee()->setClear();
        }
    }
}

void Equipe::refill()
{
    for(size_t i=0;i<this->m_cycliste.size();i++)
    {
        this->m_endurance[i]=this->m_endurance[i]+this->m_recuperation[i];
    }
}

std::unordered_map<std::string,std::string> Equipe::selectionCourse(std::vector<std::string>tracks,std::vector<std::string>t1,std::vector<std::string>t2,std::vector<std::string>t3,std::vector<std::string>t4)
{
    std::unordered_map<std::string,std::string> Circuits;
    int c1=10;
    int c2=10;
    int random;
    for(int i=0;i<3;i++)
    {
        do{
        random=rand()%4;
        }while(random==c1 || random==c2);
        if(i==0)
        {
            c1=random;
        }
        if(i==1)
        {
            c2=random;
        }
        if(random==0)
        {
            int random1=rand()%3;
            Circuits.insert({tracks[random],t1[random1]});
        }
        if(random==1)
        {
            int random1=0;
            Circuits.insert({tracks[random],t2[random1]});
        }
        if(random==2)
        {
            int random1=rand()%3;
            Circuits.insert({tracks[random],t3[random1]});
        }
        if(random==3)
        {
            int random1=rand()%2;
            Circuits.insert({tracks[random],t4[random1]});
        }


    }
    return Circuits;
}

void Equipe::afficherCircuits(std::unordered_map<std::string,std::string> c)
{
    int compteur=0;

    for(const auto& elem : c)
    {
        compteur=compteur+1;
        std::cout <<compteur<<": " << elem.first << std::endl;
        std::cout << "avec le poids de: " << elem.second << std::endl;
    }
}


void Equipe::AI(graphe g)
{
    unsigned int taille=g.getM_arrete().size();
    for(unsigned int i=0;i<m_cycliste.size();i++)
    {
        m_poids[i]=g.binaire(taille,2);
    }

}





void Equipe::ScoreEtape(Equipe Prof, Equipe Pro, Equipe Dev)
{
    std::vector<float> p;
    for(unsigned int i=0;i<this->m_cycliste.size();i++)
    {
        p.push_back(this->m_poids[i]);
        p.push_back(Prof.m_poids[i]);
        p.push_back(Pro.m_poids[i]);
        p.push_back(Dev.m_poids[i]);
    }
        sort(p.begin(),p.end());
}
