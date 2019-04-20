#include "menu.h"

int menu (BITMAP* buffer)
{
    BITMAP *background = load_bitmap("Bitmaps/piscinefond.bmp",NULL); ///On ouvre le fichier de l'image de fond du menu
    BITMAP *accueil = load_bitmap("Bitmaps/menubase.bmp",NULL);
    BITMAP *bouton1= load_bitmap("Bitmaps/menubouton1.bmp",NULL);
    BITMAP *bouton2= load_bitmap("Bitmaps/menubouton2.bmp",NULL);
    BITMAP *bouton3 = load_bitmap("Bitmaps/menubouton3.bmp",NULL);
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

        if (mouse_x>277 && mouse_x<499)
        {
            if (mouse_y>249 && mouse_y<354)
            {
                draw_sprite(buffer, bouton3,0,0);
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

int menu_prim (BITMAP* prim_buffer)
{
    BITMAP *prim_fond = load_bitmap("Bitmaps/piscinefond.bmp",NULL); /// Réutiliser la même bitmap pour Pareto
    BITMAP *prim_base = load_bitmap("Bitmaps/prim_base.bmp",NULL);
    BITMAP *prim_1 = load_bitmap("Bitmaps/prim_1.bmp",NULL);
    BITMAP *prim_2 = load_bitmap("Bitmaps/prim_2.bmp",NULL);
    BITMAP *prim_return = load_bitmap("Bitmaps/prim_return.bmp",NULL);
    draw_sprite(prim_buffer,prim_base,0,0);
    ///std::cout<<"test prim";
    blit (prim_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    int chosen = 0;


    while (!key[KEY_ESC])
    {
        //std::cout<<"testprim";
        blit(prim_fond,prim_buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(prim_buffer,prim_base,0,0);


        if (mouse_x> 64 && mouse_x< 263)
        {
            if (mouse_y> 482 && mouse_y< 549) // sur bouton retour
            {

                draw_sprite (prim_buffer,prim_return, 0,0);
                if (mouse_b & 1)
                {
                    chosen = 1;
                    break;
                }
            }

        }

        if (mouse_x> 147 && mouse_x<362 ) // bouton 1er poids
        {
            if (mouse_y> 226 && mouse_y< 329)
            {
                draw_sprite(prim_buffer,prim_1,0,0);
                if (mouse_b&1)
                {
                    chosen = 2;
                    break;
                }
            }
        }

        if (mouse_x> 433 && mouse_x<652) // bouton 2eme poids
        {
            if (mouse_y>228 && mouse_y< 328)
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

int menu_pareto (BITMAP* pareto_buffer)
{
    int pareto_choice = 0;
    BITMAP *pareto_fond = load_bitmap("Bitmaps/piscinefond.bmp",NULL);
    BITMAP *pareto_base = load_bitmap("Bitmaps/pareto_base.bmp",NULL);
    BITMAP *pareto_1 = load_bitmap("Bitmaps/pareto_1.bmp",NULL);
    BITMAP *pareto_2 = load_bitmap("Bitmaps/pareto_2.bmp",NULL);
    BITMAP *pareto_return = load_bitmap("Bitmaps/pareto_return.bmp",NULL);
    //draw_sprite(pareto_buffer,pareto_base,0,0);
    blit (pareto_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    while (!key[KEY_ESC])
    {
        blit(pareto_fond,pareto_buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        draw_sprite(pareto_buffer,pareto_base,0,0);
        if (mouse_x>240 && mouse_x< 544)
        {
            if (mouse_y>88 && mouse_y<204)
            {
                draw_sprite(pareto_buffer, pareto_1,0,0);
                if (mouse_b&1)
                {
                    pareto_choice = 2;
                    break;
                }
            }
        }
        if (mouse_x>184 && mouse_x< 590)
        {
            if (mouse_y>228 && mouse_y<357)
            {
                draw_sprite(pareto_buffer, pareto_2,0,0);
                if (mouse_b&1)
                {
                    pareto_choice = 1;
                    break;
                }
            }
        }
        if (mouse_x>79 && mouse_x<277)
        {
            if( mouse_y> 450 && mouse_y< 517)
            {
                draw_sprite(pareto_buffer,pareto_return,0,0);
                {
                    if (mouse_b&1)
                    {
                        pareto_choice = 3;
                        break;
                    }
                }
            }
        }

        blit (pareto_buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(pareto_buffer);
    }
    return pareto_choice;
}

void allegro()
{
    //BITMAP*page;
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
    install_mouse();
    show_mouse(screen);

    // CREATION DU BUFFER D'AFFICHAGE à la taille de l'écran
    //page=create_bitmap(SCREEN_W,SCREEN_H);
    //clear_bitmap(page);
}

void lanceur_prog()
{
    allegro();
    int taille;
    int choix=0;
    int choix_prim=0;
    int choix_pareto=0;
    int choixAffichagePareto = 0;
    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(buffer);
    std::vector<std::string> fdjv={"Jacky la Frite", "Mr Quarate" , "Adrien Nougaret" , "Frederic Luu"};
    std::vector<std::string> tracks={"broadway.txt","cubetown.txt","manhattan.txt","triville.txt"};
    std::vector<std::string> t1={"broadway_weights_0.txt","broadway_weights_1.txt","broadway_weights_2.txt"};
    std::vector<std::string> t2={"cubetown_weights_0.txt"};
    std::vector<std::string> t3={"manhattan_weights_0.txt","manhattan_weights_1.txt","manhattan_weights_2.txt"};
    std::vector<std::string> t4={"triville_weights_0.txt","triville_weights_1.txt"};
    std::vector<graphe> t;
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
    graphe g{"broadway.txt","broadway_weights_0.txt"};
    std::vector<Arrete*> p1;
    p1=g.prim(1);
    std::vector<Arrete*> p2;
    p2=g.prim(2);
    taille=g.getM_arrete().size();
    while(!key[KEY_ESC])
    {
        choix = menu(buffer); // récup choix (pour switch)
        switch (choix)
        {
        case 1 : //Bouton 1 du menu principal choisi
        {
            choix = 0;
            choix_prim= menu_prim(buffer);
            switch (choix_prim)
            {
            case 1 :
                choix_prim = 0;
                menu(buffer);
                break;
            case 2 :
            {
                choix_prim=0;
                g.afficherPrim(p1);
                while(!key[KEY_ENTER])
                {

                }
                break;
            }///Algorithme de Prim selon le 1er poids

            case 3 :
            {
                choix_prim = 0;
                g.afficherPrim(p2);
                while(!key[KEY_ENTER])
                {

                }

                break;
            }///Algorithme de Prim selon le 2nd poids

            }
            break;
        }
        case 2 : //Bouton 2 du menu principal choisi
        {
            choix = 0;
            choix_pareto = menu_pareto(buffer);
            switch(choix_pareto)
            {
            case 1 :
            {
                choix_pareto = 0;
                std::cout<<std::endl<<"tapez 1 pour les meilleures solutions ou 2 pour les pires"<<std::endl;
                std::cin>> choixAffichagePareto;
                g.binaire(taille,1, choixAffichagePareto);
                std::cout<<"test2";
                g.placerPointsMini();///Affichage du diagramme de Pareto
                while(!key[KEY_ENTER])
                {

                }
                break;
            }
            case 2 :
                choix_pareto = 0;
                std::cout<<"tapez 1 pour les meilleures solutions ou 2 pour les pires"<<std::endl;
                std::cin>> choixAffichagePareto;
                g.binaire(taille,0, choixAffichagePareto);
                std::cout<<"test";
                g.placerPointsMini();///Affichage du diagramme de Pareto
                while(!key[KEY_ENTER])
                {

                }
                break;
            case 3 :
                choix_pareto = 0;
                menu(buffer);
                break;
            }
            break;
        }
        case 3 : //Bouton QUITTER du menu principal
            allegro_exit();
            break;
        case 4 :
        {
            int c=Fdjv.selection(Fdjv,Prof,Pro,Dev);
            std::unordered_map<std::string,std::string> Liste=Fdjv.selectionCourse(tracks,t1,t2,t3,t4);
            Fdjv.afficherCircuits(Liste);
            //blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            for(const auto& elem : Liste)
            {
                graphe g = (graphe(elem.first,elem.second));
                t.push_back(g);
            }
            if(c==1)
            {
                Fdjv.setMarque();
                system("cls");
                std::cout << "cliquez sur la fenetre Allegro" << std::endl;
                for(int i=0; i<3; i++)
                {
                    Fdjv.course(t[i]);
                    Fdjv.refill();
                    Prof.refill();
                    Pro.refill();
                    Dev.refill();

                }
            }
            if(c==2)
            {
                Prof.setMarque();
                for(int i=0; i<3; i++)
                {
                    Prof.course(t[i]);
                    Fdjv.refill();
                    Prof.refill();
                    Pro.refill();
                    Dev.refill();
                }
            }
            if(c==3)
            {
                Pro.setMarque();
                for(int i=0; i<3; i++)
                {
                    Pro.course(t[i]);
                    Fdjv.refill();
                    Prof.refill();
                    Pro.refill();
                    Dev.refill();
                }
            }
            if(c==4)
            {
                Dev.setMarque();
                for(int i=0; i<3; i++)
                {
                    Dev.course(t[i]);
                    Fdjv.refill();
                    Prof.refill();
                    Pro.refill();
                    Dev.refill();
                }
            }
            std::cout << "Fin" << std::endl;

        }
        break;
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}
