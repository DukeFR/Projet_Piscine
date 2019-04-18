#include <iostream>
#include "Graph.h"
#include "Sommet.h"
#include "Arrete.h"
#include <allegro.h>
#include <time.h>
#include <math.h>

int menu ()
{
    install_mouse();
    show_mouse(screen);
    BITMAP *buffer = create_bitmap(SCREEN_W,SCREEN_H);/// création du buffer
    BITMAP *background = load_bitmap("Bitmaps/piscinefond.bmp",NULL); ///On ouvre le fichier de l'image de fond du menu
    BITMAP *accueil = load_bitmap("Bitmaps/menubase.bmp",NULL);
    BITMAP *bouton1= load_bitmap("Bitmaps/menubouton1.bmp",NULL);
    BITMAP *bouton2= load_bitmap("Bitmaps/menubouton2.bmp",NULL);
    BITMAP *quitter= load_bitmap("Bitmaps/quitter.bmp",NULL);
    draw_sprite(buffer,accueil,0,0); /// dessine la totalité de l'image accueil sur le buffer
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    int choice = 0;

    while (!key[KEY_ESC])
        {
            blit(background,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(buffer,accueil,0,0);

            if (mouse_x>94 && mouse_x<296) ///double boucle souris sur le premier bouton
            {
                if (mouse_y>62 && mouse_y<163)
                {
                    draw_sprite(buffer,bouton1,0,0);
                    if (mouse_b & 1)
                    {
                        choice = 1;
                        break;
                    }
                }
            }

                if (mouse_x>504 && mouse_x<707) ///double boucle souris sur le second bouton
            {
                if (mouse_y>63 && mouse_y<167)
                {
                    draw_sprite(buffer,bouton2,0,0);
                    if (mouse_b & 1)
                    {
                        choice = 2;
                        break;
                    }
                }
             }

             if (mouse_x>216 && mouse_x<548) ///double boucle souris sur le bouton QUITTER
            {
                if (mouse_y>450 && mouse_y<556)
                {
                    draw_sprite(buffer,quitter,0,0);
                    if (mouse_b & 1)
                    {
                        choice = 3;
                        break;
                    }
                }
             }

        blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(buffer);
        }
return choice;
}





/*int menu_prim ()
{
    int chosen = 0;
    install_mouse();
    show_mouse(screen);
    BITMAP *prim_buffer = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *prim_fond = load_bitmap("Bitmaps/fond.bmp",NULL); /// Réutiliser la même bitmap pour Pareto
    BITMAP *prim_base = load_bitmap("Bitmaps/primbase.bmp",NULL);
    BITMAP *prim_1 = load_bitmap("Bitmaps/prim1.bmp",NULL);
    BITMAP *prim_2 = load_bitmap("Bitmaps/prim2.bmp",NULL);
    BITMAP *prim_return = load_bitmap("Bitmaps/prim_return",NULL);
    draw_sprite (prim_buffer,prim_base,0,0);
    blit (prim_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    while (!key[KEY_ESC])
    {
        if (mouse_x>xprimin && mouse_x< xprimax)
            {
                if (mouse_y> yprimin && mouse_y< yprimax) // sur bouton retour
                {
                    draw_sprite (prim_buffer,retour, 0,0)
                    if (mouse_b & 1)
                    {
                        chosen = 1;
                        break;
                    }
                }

            }
        if (mouse_x> oui && mouse_x< non ) // bouton 1er poids
        {
            if (mouse_y> yes && mouse_y<no)
            {
                draw_sprite(prim_buffer,prim_1,0,0);
                if (mouse_b&1)
                {
                    chosen = 2;
                    break;
                }
            }
        }
        if (mouse_x> hello && mouse_x<hello) // bouton 2eme poids
        {
            if (mouse_y>bonjour && mouse_y< bisous)
            {
                draw_sprite(prim_buffer,prim_2,0,0);
                if (mouse_b & 1)
                {
                    chosen = 3;
                    break;
                }
            }
        }

        blit(prim_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(prim_buffer);
    }
     return chosen;
}

int menu_pareto ()
{
    int pareto_choice = 0;
    install_mouse();
    show_mouse(screen);
    BITMAP *pareto_buffer = create_bitmap(SCREEN_W,SCREEN_H);
    BITMAP *pareto_fond = load_bitmap("Bitmaps/fond.bmp",NULL);
    BITMAP *pareto_base = load_bitmap("Bitmaps/pareto_base.bmp",NULL);
    BITMAP *pareto_1 = load_bitmap("Bitmaps/pareto_1.bmp",NULL);
    BITMAP *pareto_return = load_bitmap("Bitmaps/pareto_return.bmp",NULL);
    draw_sprite(pareto_buffer,pareto_base,0,0);
    blit (pareto_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    while (!key[KEY_ESC])
    {
        if (mouse_x>quoi && mouse_x< qui)
        {
            if (mouse_y>quand && mouse_y< ou)
            {
                draw_sprite(pareto_buffer, pareto_1,0,0);
                if (mouse_b&1)
                {
                    pareto_choice = 1;
                    break;
                }
            }
        }
        if (mouse_x>ouais && mouse_x<lol)
        {
            if( mouse_y>voiture &&mouse_y>bonbon)
            {
                draw_sprite(pareto_buffer,pareto_return)
                {
                    pareto_choice = 2;
                    break;
                }
            }
        }

        blit (pareto_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(pareto_buffer);
    }
    return pareto_choice;
}*/

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
    int taille;
    std::vector<Arrete*> p;
    //std::vector<graphe> b;
    graphe g{"broadway.txt","broadway_weights_0.txt"};
    g.afficher();
    //menu();
    taille=g.getM_arrete().size();

    //g.placerPoints();
    //g.dessinerGraphePoids();

     while (!key[KEY_ESC])
    {
        int choix=0;
        int choix_prim=0;
        int choix_pareto=0;
        choix = menu(); // récup choix (pour switch)
        switch (choix)
        {
            {
                case 1 : //Bouton 1 du menu principal choisi
                    choix_prim= 0;//menu_prim();
                    switch (choix_prim)
                    {
                        case 1 :menu();
                        break;
                        case 2 : {p=g.prim(1);
                                  g.afficherPrim(p);}///Algorithme de Prim selon le 1er poids
                            break;
                        case 3 : {p=g.prim(2);
                                  g.afficherPrim(p);}///Algorithme de Prim selon le 2nd poids
                            break;
                    }break;
                case 2 : //Bouton 2 du menu principal choisi
                    choix_pareto = 0;//menu_pareto();
                    switch(choix_pareto)
                    {
                    case 1 : g.binaire(taille);
                             g.placerPointsMini();///Affichage du diagramme de Pareto
                        break;
                    case 2 : menu();
                        break;
                    }break;
                case 3 : //Bouton QUITTER du menu principal
                    allegro_exit();
                    break;
            }
        }
    }

    return 0;
}
END_OF_MAIN();


