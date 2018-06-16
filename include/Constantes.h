#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define TOUCHE_AVANT SDL_SCANCODE_W
#define TOUCHE_ARRIERE SDL_SCANCODE_S
#define TOUCHE_DROITE SDL_SCANCODE_D
#define TOUCHE_GAUCHE SDL_SCANCODE_A
#define TOUCHE_HAUT SDL_SCANCODE_SPACE
#define TOUCHE_BAS SDL_SCANCODE_LSHIFT

#define LARGEUR_ECRAN 800
#define HAUTEUR_ECRAN 600

