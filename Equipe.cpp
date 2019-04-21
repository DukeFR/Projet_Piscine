#include "Equipe.h"
#include <algorithm>


Equipe::Equipe(std::string name,std::vector<std::string> n, std::vector<int> e, std::vector<int> p,std::vector<int> r,std::vector<int> poids) :m_nom{name}, m_cycliste{n}, m_endurance{e}, m_point{p},m_marque{false},m_poids{poids},m_recuperation{r}
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
        std::cout << E.m_cycliste[i] << " " << "Endurance: " << E.m_endurance[i] << " " << "Poids: " << E.m_poids[i] << std::endl;
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

void Equipe::setPoints(int valeur,int i)
{
    m_point[i]=m_point[i]+valeur;
}

void Equipe::setPoids(float valeur, int i)
{
    m_poids[i]=valeur;
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
    for(unsigned int i=0;i<4;i++)
    {
        this->m_poids[i]=0;
    }
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
                        std::cout << "Vous etes au sommet: " << v->getDepart()->getm_id() << std::endl;
                        std::cout << "Aller vers le sommet: " << v->getArrivee()->getm_id() << " en passant par l'arete: " << v->getm_id()<< " avec une perte d'endurance de: " << v->getPoids1() << std::endl;
                        choixP.insert(v->getm_id());
                    }
                    if(v->getDepart()->getMarque()==false)
                    {
                        std::cout << "Vous etes au sommet: " << v->getArrivee()->getm_id() << std::endl;
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

std::unordered_map<std::string,std::string> Equipe::selectionCourse(std::vector<std::string>tracks,std::vector<std::string>t1,std::vector<std::string>t2,std::vector<std::string>t4)
{
    std::unordered_map<std::string,std::string> Circuits;
    int c1=10;
    int c2=10;
    int random;
    for(int i=0;i<3;i++)
    {
        do{
        random=rand()%3;
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
    float valeur;
    unsigned int taille=g.getM_arrete().size();
    for(unsigned int i=0;i<m_cycliste.size();i++)
    {
        valeur=g.binaire(taille,2);
        this->setPoids(valeur,i);
    }


}

bool tri(cycliste* a, cycliste* b)
{
    return a->getPoids()< b->getPoids();
}

bool triP(cycliste* a, cycliste* b)
{
    return a->getPoint()< b->getPoint();
}




void Equipe::ScoreEtape(Equipe* Prof, Equipe* Pro, Equipe* Dev)
{
    std::vector<cycliste*> liste;
    for(unsigned int i=0; i<this->m_cycliste.size();i++)
    {
        liste.push_back(new cycliste(m_nom,m_cycliste[i],m_poids[i]));
        liste.push_back(new cycliste(Prof->m_nom,Prof->m_cycliste[i],Prof->m_poids[i]));
        liste.push_back(new cycliste(Pro->m_nom,Pro->m_cycliste[i],Pro->m_poids[i]));
        liste.push_back(new cycliste(Dev->m_nom,Dev->m_cycliste[i],Dev->m_poids[i]));
    }

    sort(liste.begin(),liste.end(),tri);
    int point=16;
    system("cls");
    std::cout << "----------- " << "CLASSEMENT ETAPE" <<" -----------" << std::endl;
    for(unsigned int i=0;i<liste.size();i++)
    {
        std::cout << i+1 << "eme: " << liste[i]->getCoureur() << "  Temps: " << liste[i]->getPoids() << std::endl;
        if(liste[i]->getId()==this->m_nom)
        {
            for(unsigned int j=0;j<this->m_cycliste.size();j++)
            {
                if(liste[i]->getCoureur()==this->m_cycliste[j])
                {
                    this->setPoints(point,j);
                    point=point-1;
                }
            }
        }
        if(liste[i]->getId()==Prof->m_nom)
        {
            for(unsigned int j=0;j<this->m_cycliste.size();j++)
            {
                if(liste[i]->getCoureur()==Prof->m_cycliste[j])
                {
                    Prof->setPoints(point,j);
                    point=point-1;
                }
            }
        }
        if(liste[i]->getId()==Pro->m_nom)
        {
            for(unsigned int j=0;j<this->m_cycliste.size();j++)
            {
                if(liste[i]->getCoureur()==Pro->m_cycliste[j])
                {
                    Pro->setPoints(point,j);
                    point=point-1;
                }
            }
        }
        if(liste[i]->getId()==Dev->m_nom)
        {
            for(unsigned int j=0;j<this->m_cycliste.size();j++)
            {
                if(liste[i]->getCoureur()==Dev->m_cycliste[j])
                {
                    Dev->setPoints(point,j);
                    point=point-1;
                }
            }
        }
    }
}


void Equipe::ScoreT(Equipe Prof, Equipe Pro, Equipe Dev)
{
    std::vector<cycliste*> D;
    for(unsigned int i=0; i<this->m_cycliste.size();i++)
    {
        D.push_back(new cycliste(m_nom,m_cycliste[i],0,m_point[i]));
        D.push_back(new cycliste(Prof.m_nom,Prof.m_cycliste[i],0,Prof.m_point[i]));
        D.push_back(new cycliste(Pro.m_nom,Pro.m_cycliste[i],0,Pro.m_point[i]));
        D.push_back(new cycliste(Dev.m_nom,Dev.m_cycliste[i],0,Dev.m_point[i]));
    }

    sort(D.begin(),D.end(),triP);
    system("cls");
    std::cout << "----------- " << "CLASSEMENT GENERAL" <<" -----------" << std::endl;
    std::cout << D[15]->getCoureur() << " " << D[15]->getPoint() << " points" << std::endl;
    std::cout << D[14]->getCoureur() << " " << D[14]->getPoint() << " points" << std::endl;
    std::cout << D[13]->getCoureur() << " " << D[13]->getPoint() << " points" << std::endl;
    std::cout << D[12]->getCoureur() << " " << D[12]->getPoint() << " points"<< std::endl;
    std::cout << D[11]->getCoureur() << " " << D[11]->getPoint() << " points"<< std::endl;
    std::cout << D[10]->getCoureur() << " " << D[10]->getPoint() << " points"<< std::endl;
    std::cout << D[9]->getCoureur() << " " << D[9]->getPoint() << " points"<< std::endl;
    std::cout << D[8]->getCoureur() << " " << D[8]->getPoint() << " points"<< std::endl;
    std::cout << D[7]->getCoureur() << " " << D[7]->getPoint() << " points"<< std::endl;
    std::cout << D[6]->getCoureur() << " " << D[6]->getPoint() << " points"<< std::endl;
    std::cout << D[5]->getCoureur() << " " << D[5]->getPoint() << " points"<< std::endl;
    std::cout << D[4]->getCoureur() << " " << D[4]->getPoint() << " points"<< std::endl;
    std::cout << D[3]->getCoureur() << " " << D[3]->getPoint() << " points"<< std::endl;
    std::cout << D[2]->getCoureur() << " " << D[2]->getPoint() << " points"<< std::endl;
    std::cout << D[1]->getCoureur() << " " << D[1]->getPoint() << " points"<< std::endl;
    std::cout << D[0]->getCoureur() << " " << D[0]->getPoint() << " points"<< std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
}

