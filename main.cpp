#include <iostream>
#include "Graph.h"
#include "Sommet.h"
#include "Arrete.h"


int main()
{
    graphe g{"broadway.txt"};
    g.afficher();
    return 0;
}
