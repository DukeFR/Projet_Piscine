#include "Equipe.h"


Equipe::Equipe(std::string name,std::vector<std::string> n, std::vector<int> e, std::vector<int> p,std::vector<int> r) :m_nom{name}, m_cycliste{n}, m_endurance{e}, m_point{e},m_marque{false},m_poids{0},m_recuperation{r}
{

}

void Equipe::selection(Equipe Fdjv,Equipe Prof,Equipe Pro,Equipe Dev)
{
    int choix;
    system("cls");
    std::cout <<"-----------------Selectionnez votre equipe-----------------" << std::endl;
    for(int i=0;i<2;i++)
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
    do {
        std::cin >>choix;
    }while (choix!=1 && choix!=2 && choix!=3 && choix!=4);
    if(choix==1)
    {

    }

}

void Equipe::affichage(Equipe E)
{
    std::cout << E.m_nom << ": "<< std::endl;
    for(unsigned int i=0;i<E.m_cycliste.size();i++)
    {
        std::cout << E.m_cycliste[i] << " " << "Endurance: " << E.m_endurance[i] << std::endl;
    }
}

void Equipe::setMarque()
{
    m_marque=true;
}
