#ifndef CYCLISTE_H_INCLUDED
#define CYCLISTE_H_INCLUDED

#include <iostream>
#include <string>


class cycliste
{
    public:
        cycliste(std::string E, std::string C, float P);
        cycliste(std::string E, std::string C,float Poid,int P);
        float getPoids();
        std::string getCoureur();
        std::string getId();
        int getPoint();


private:
    std::string m_idEquipe;
    std::string m_idCoureur;
    float m_poids;
    int m_point;
};

#endif // CYCLISTE_H_INCLUDED
