#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "Graph.h"
#include "Sommet.h"
#include "Arrete.h"
#include <allegro.h>
#include <time.h>
#include "Equipe.h"
#include "Cycliste.h"
#include <math.h>

int menu_pareto (BITMAP* pareto_buffer);
int menu_prim (BITMAP* prim_buffer);
int menu (BITMAP* buffer);
void allegro();
void lanceur_prog();

#endif // MENU_H_INCLUDED
