#include "Constantes.h"
#include "Bloc.h"
#include "BlocMultiTexture.h"
#include "Texture.h"
#include "CameraVolante.h"
#include "Input.h"


bool pause=false;


SDL_Window* fenetre(0);
SDL_GLContext contexteOpenGL(0);

Texture terre;
Texture herbeDessus;
Texture herbeCote;

Bloc bloc1;
BlocMultiTexture bloc2;


void dessineScene(){
    // Nettoyage de l'�cran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

    glMatrixMode(GL_MODELVIEW);
    bloc1.affiche();
    bloc2.affiche();

    // Actualisation de la fen�tre
    SDL_GL_SwapWindow(fenetre);
}

void jeu(){
    CameraVolante cam(0,0,0);
    Input input;


    Uint32 debutImage, tempsImage; //nouvelle variable
    SDL_Event evenements;

    while(!input.quit)
    {
        debutImage=SDL_GetTicks();
        input.updateInput(evenements);


        if(input.key[SDL_SCANCODE_ESCAPE]){
            pause=SDL_GetRelativeMouseMode();
            SDL_SetRelativeMouseMode(SDL_bool(!SDL_GetRelativeMouseMode()));
            input.key[SDL_SCANCODE_ESCAPE]=false;

            if(pause){
                SDL_WarpMouseInWindow(fenetre, LARGEUR_ECRAN/2, HAUTEUR_ECRAN/2);
            }

        }
        if(!pause){
            cam.gestionEvenements(input);
        }


        dessineScene();
        cam.affiche();


        tempsImage=SDL_GetTicks()-debutImage;
        if(tempsImage<10){
            SDL_Delay(10 - tempsImage);
        }
    }


}
void initScene(){
    bloc1 = Bloc(0,0,0,1,1,1, terre.getID());
    bloc2 = BlocMultiTexture(3,0,0,1,1,1, herbeCote.getID(), herbeDessus.getID(), terre.getID());
}

void initTexture(){
    terre.charger("dirt.png");
    herbeDessus.charger("grass_top.png");
    herbeCote.charger("grass_side.png");
}

int init(){
    // Initialisation de la SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return -1;
    }

    // Version d'OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // Double Buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Cr�ation de la fen�tre
    fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_ECRAN, HAUTEUR_ECRAN, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    if(fenetre == 0)
    {
        std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
        SDL_Quit();

        return -1;
    }



    // Cr�ation du contexte OpenGL

    contexteOpenGL = SDL_GL_CreateContext(fenetre);

    if(contexteOpenGL == 0)
    {
        std::cout << SDL_GetError() << std::endl;
        SDL_DestroyWindow(fenetre);
        SDL_Quit();

        return -1;
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)LARGEUR_ECRAN/HAUTEUR_ECRAN, 0.01, 1000);

    glClearColor(0.42,0.796,1,1);
    return 0;
}


int main(int argc, char **argv)
{
    init();
    initTexture();
    initScene();

    jeu();

    SDL_GL_DeleteContext(contexteOpenGL);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}