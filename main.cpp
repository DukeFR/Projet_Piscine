#include <iostream>
#include "Graph.h"
#include "Sommet.h"
#include "Arrete.h"
#include "Equipe.h"
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

std::unordered_map<std::string,std::string> selectionCourse(std::vector<std::string>tracks,std::vector<std::string>t1,std::vector<std::string>t2,std::vector<std::string>t3,std::vector<std::string>t4)
{
    std::unordered_map<std::string,std::string> Circuits;
    int c1=10;
    int c2=10;
    int random;
    for(int i=0;i<3;i++)
    {
        do{
        random=rand()%4;
        }while(random==c1 || random==c2);
        if(i==0)
        {
            c1=random;
        }
        if(i==2)
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
            int random1=rand()%3;
            Circuits.insert({tracks[random],t3[random1]});
        }
        if(random==3)
        {
            int random1=rand()%2;
            Circuits.insert({tracks[random],t4[random1]});
        }


    }
    return Circuits;
}

void afficherCircuits(std::unordered_map<std::string,std::string> c)
{
    int compteur=0;

    for(const auto& elem : c)
    {
        compteur=compteur+1;
        std::cout <<compteur<<": " << elem.first << std::endl;
        std::cout << "avec le poids de: " << elem.second << std::endl;
    }
}






int main()
{
    allegro();
    int c = 10;
    int taille;
    int nombre;
    BITMAP* buffer=create_bitmap(SCREEN_W,SCREEN_H);
    std::vector<std::string> fdjv={"Jacky la Frite", "Mr Quarate" , "Adrien Nougaret" , "Frederic Luu"};
    std::vector<std::string> tracks={"broadway.txt","cubetown.txt","manhattan.txt","triville.txt"};
    std::vector<std::string> t1={"broadway_weights_0.txt","broadway_weights_1.txt","broadway_weights_2.txt"};
    std::vector<std::string> t2={"cubetown_weights_0.txt"};
    std::vector<std::string> t3={"manhattan_weights_0.txt","manhattan_weights_1.txt","manhattan_weights_2.txt"};
    std::vector<std::string> t4={"triville_weights_0.txt","triville_weights_1.txt"};
    std::vector<graphe > t;
    std::vector<int> e1= {95,85,90,75};
    std::vector<int> r1= {47,42,45,37};
    std::vector<int> pt ={0,0,0,0};
    Equipe Fdjv{"FDJV",fdjv,e1,pt,r1};
    std::vector<std::string>  dev={"Mark-Andrew","Xavier","Miriam","Jasmine"};
    std::vector<int> e2= {85,85,85,85};
    std::vector<int> r2= {42,42,42,42};
    Equipe Dev{"Les developpeurs",dev,e2,pt,r2};
    std::vector<std::string> prof={"Fercoq","Segado","Rendler","Palasi"};
    std::vector<int> e3=  {100,80,85,80};
    std::vector<int> r3= {50,40,42,40};
    Equipe Prof{"Prof",prof,e3,pt,r3};
    std::vector<std::string> pro={"Contador","Froome","Nibali","Bardet"};
    std::vector<int> e4={90,90,90,90};
    std::vector<int> r4= {45,45,45,45};
    Equipe Pro{"Les Pros",pro,e4,pt,r4};
    std::vector<Arrete*> p;
    //std::vector<graphe> b;
    graphe g{"manhattan.txt","manhattan_weights_0.txt"};
    g.afficher();
    //menu();
    taille=g.getM_arrete().size();

    g.placerPoints();
    g.dessinerGraphePoids();
    do{
    std::cout<<"Voulez-vous prendre en compte le premier poids ou le second?" << std::endl;
    std::cout<<"1. 1er Poids"<< std::endl;
    std::cout<<"2. 2eme Poids"<<std::endl;
    std::cout<<"3. Toutes les possibilites binaires"<<std::endl;
    std::cout <<"4. Optimisation bi-objectif" << std::endl;
    std::cout <<"5. Tour de France 2019" << std::endl;
    std::cin>>c;
    }while(c!=1 && c!=2 && c!=3 && c!=4 && c!=5);
    if(c==1 || c==2)
    {
    p=g.prim(c);
    g.afficherPrim(p);}
    if(c==3)
    {
        //taille=pow(2,taille);
        nombre=g.binaire(taille,1);
        g.placerPointsMini();
        std::cout << "n :" << nombre<< std::endl;
        if(nombre==1)
        {
            menu();
        }

    }
    if(c==4)
    {
        g.binaire(taille,0);

    }
    if(c==5)
    {
        Fdjv.selection(Fdjv,Prof,Pro,Dev);
        std::unordered_map<std::string,std::string> Liste=selectionCourse(tracks,t1,t2,t3,t4);
        afficherCircuits(Liste);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        int compteur=0;
        for(const auto& elem : Liste)
        {
            graphe g = (graphe(elem.first,elem.second));
            t.push_back(g);
        }
        t[compteur].placerPoints();
        compteur++;
        while(!key[KEY_SPACE])
        {
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        t[compteur].placerPoints();
        compteur++;
        while(!key[KEY_SPACE])
        {
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        t[compteur].placerPoints();
        compteur++;
        while(!key[KEY_SPACE])
        {
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);



    }
    while (!key[KEY_ESC])
    {

    }
    return 0;
}
END_OF_MAIN();


