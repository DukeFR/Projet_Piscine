#include "cycliste.h"

cycliste::cycliste(std::string E, std::string C, float P) : m_idEquipe{E}, m_idCoureur{C}, m_poids{P}
{

}

cycliste::cycliste(std::string E, std::string C,float Poid,int P) : m_idEquipe{E}, m_idCoureur{C}, m_point{P},m_poids{Poid}
{

}

float cycliste::getPoids()
{
    return m_poids;
}

int cycliste::getPoint()
{
    return m_point;
}

std::string cycliste::getCoureur()
{
    return m_idCoureur;
}

std::string cycliste::getId()
{
    return m_idEquipe;
}
