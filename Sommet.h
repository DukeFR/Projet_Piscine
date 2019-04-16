
#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <iostream>
class Sommet
{
    public:
        ///constructeur qui reçoit en params les données du sommet
        Sommet(int,int,int);
        //void ajouterVoisin(const Sommet*);
        void afficherData() const;
        //void afficherVoisins() const;
        ~Sommet();
        void setMarque();
        bool getMarque();
        int getm_x();
        int getm_y();
        int getm_id();

    protected:

    private:
        /// Voisinage : liste d'adjacence
        //std::vector<const Sommet*> m_voisins;

        /// Données spécifiques du sommet
        int m_id; // Identifiant
        bool marque;
        int m_x;
        int m_y;

};

#endif // SOMMET_H_INCLUDED


