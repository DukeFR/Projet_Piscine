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
    BITMAP *bouton3= load_bitmap("Bitmaps/menubouton3.bmp",NULL);
    BITMAP *bouton4= load_bitmap("Bitmaps/menubouton4.bmp",NULL);
    draw_sprite(buffer,accueil,0,0); /// dessine la totalité de l'image accueil sur le buffer
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    int choice = 0;
    int couleur=makecol(255,0,0);

    while (!key[KEY_ESC])
        {
            blit(background,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
            draw_sprite(buffer,accueil,0,0);

            if (mouse_x>131 && mouse_x<360) ///double boucle souris sur le premier bouton
            {
                if (mouse_y>143 && mouse_y<259)
                {
                    draw_sprite(buffer,bouton1,0,0);
                    if (mouse_b & 1)
                    {
                        choice = 1;
                        break;
                    }
                }
            }

                if (mouse_x>431 && mouse_x<669) ///double boucle souris sur le second bouton
            {
                if (mouse_y>145 && mouse_y<259)
                {
                    draw_sprite(buffer,bouton2,0,0);
                    if (mouse_b & 1)
                    {
                        choice = 2;
                        break;
                    }
                }
             }

             if (mouse_x>131 && mouse_x<358) ///double boucle souris sur le troisième bouton
            {
                if (mouse_y>317 && mouse_y<428)
                {
                    draw_sprite(buffer,bouton3,0,0);
                    if (mouse_b & 1)
                    {
                        choice = 3;
                        break;
                    }
                }
            }

            if (mouse_x>437 && mouse_x<666) ///double boucle souris sur le quatrième bouton
            {
                if (mouse_y>312 && mouse_y<431)
                {
                    draw_sprite(buffer,bouton4,0,0);
                    if (mouse_b & 1)
                    {
                        choice = 4;
                        break;
                    }
                }
            }



        blit(buffer, screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(buffer);

        }
        return choice;
}


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
    int taille;
    std::vector<Arrete*> p;
    //std::vector<graphe> b;
    graphe g{"manhattan.txt","manhattan_weights_0.txt"};
    g.afficher();
    //menu();
    taille=g.getM_arrete().size();
    g.placerPoints();
    do{
    std::cout<<"Voulez-vous prendre en compte le premier poids ou le second?" << std::endl;
    std::cout<<"1. 1er Poids"<< std::endl;
    std::cout<<"2. 2eme Poids"<<std::endl;
    std::cout<<"3. Toutes les possibilites binaires"<<std::endl;
    std::cin>>c;
    }while(c!=1 && c!=2 && c!=3);
    if(c==1 || c==2)
    {p=g.prim(c);
    g.afficherPrim(p);}
    if(c==3)
    {
        //taille=pow(2,taille);
        g.binaire(taille);

    }
    while (!key[KEY_ESC])
    {

    }
    return 0;
}
END_OF_MAIN();


