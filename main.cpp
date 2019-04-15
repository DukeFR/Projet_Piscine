#include <iostream>
#include "Graph.h"
#include "Sommet.h"
#include "Arrete.h"
#include <allegro.h>
#include <time.h>


void allegro()
{
    BITMAP*page;
    // On va utiliser du hasard
    srand(time(NULL));

    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // CREATION DU BUFFER D'AFFICHAGE à la taille de l'écran
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
}

int main()
{
    allegro();
    int c=10;
    graphe g{"triville.txt"};
    std::vector<Arrete*> p;
    g.afficher();
    g.placerPoints();
    do{
    std::cout<<"Voulez-vous prendre en compte le premier poids ou le second?" << std::endl;
    std::cout<<"1. 1er Poids"<< std::endl;
    std::cout<<"2. 2eme Poids"<<std::endl;
    std::cin>>c;
    }while(c!=1 && c!=2);
    p=g.prim(c);
    g.afficherPrim(p);
    while (!key[KEY_ESC])
    {

    }
    return 0;
}
END_OF_MAIN();


