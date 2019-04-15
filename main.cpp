#include <iostream>
#include "Graph.h"
#include "Sommet.h"
#include "Arrete.h"
#include "allegro.h"
#include <time.h>


void allegro()
{
    srand(time(NULL));
    BITMAP *page;
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
    BITMAP*page;
    allegro();
    graphe g{"broadway.txt"};
    g.afficher();
    while (!key[KEY_ESC])
    {
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    return 0;
}
END_OF_MAIN();


