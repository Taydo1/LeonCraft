#include "Perso.h"

extern vector<Bloc*> carte;

Perso::Perso()
{
    //ctor
}

Perso::~Perso()
{
    //dtor
}

void Perso::pickingBloc(){
    SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 0);

    // Nettoyage de l'écran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;

    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_TEXTURE_2D);
    for(unsigned int i=0;i<carte.size();i++){
        carte[i]->affichePicking();
    }
    glEnable(GL_TEXTURE_2D);

    GLuint pixelCentre[]={0,0,0};
    glReadPixels(LARGEUR_ECRAN/2,
                 HAUTEUR_ECRAN/2,
                 1,
                 1,
                 GL_RGB,
                 GL_UNSIGNED_INT,
                 pixelCentre);

    for(int i=0;i<3;i++){
        pixelCentre[i]*=pow(2,-24);
    }

    blocVise=NULL;
    coteVise=0;
    int idDecode=pixelCentre[0]*256*256+pixelCentre[1]*256+pixelCentre[2];
    for(unsigned int i=0;i<carte.size();i++){
        for(int j=0;j<6;j++){
            if(idDecode==carte[i]->id[j]){
                blocVise=carte[i];
                coteVise=j;
            }
        }
    }
    SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 4 );
}

void Perso::detruitBloc(){
    delete blocVise;
    pickingBloc();
}

void Perso::placeBloc(){
    if(blocVise!=NULL){
        carte.push_back(new Bloc(*blocVise, coteVise));
        pickingBloc();
    }
}

void Perso::gestionEvenements(Input& input){
    if(input.mouseButton[SDL_BUTTON_LEFT]){
        detruitBloc();
        input.mouseButton[SDL_BUTTON_LEFT]=false;
    }
    if(input.mouseButton[SDL_BUTTON_RIGHT]){
        placeBloc();
        input.mouseButton[SDL_BUTTON_RIGHT]=false;
    }
}

Bloc* Perso::getBlocVise(){
    return blocVise;
}

int Perso::getCoteVise(){
    return coteVise;
}
