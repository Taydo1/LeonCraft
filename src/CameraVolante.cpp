#include "CameraVolante.h"

#include "Constantes.h"
#include "Variables.h"
#include "Perso.h"

extern Perso joueur;

double deg2rad(double deg){
    return deg*M_PI/180;
}

CameraVolante::CameraVolante(double x, double y, double z):
    x(x),
    y(y),
    z(z),
    xVise(x+1),
    yVise(0),
    zVise(0),
    angleHorizontal(0),
    angleVertical(0)
{
    affiche();
}

CameraVolante::~CameraVolante()
{
    //dtor
}

void CameraVolante::avance(){
    double vitesseHorizontale = vitesse * cos(angleVertical);
    x+=vitesseHorizontale*cos(angleHorizontal);
    y+=vitesse*sin(angleVertical);
    z+=vitesseHorizontale*sin(angleHorizontal);

    calculVise();
}

void CameraVolante::recule(){
    double vitesseHorizontale=vitesse*cos(angleVertical);
    x-=vitesseHorizontale*cos(angleHorizontal);
    y-=vitesse*sin(angleVertical);
    z-=vitesseHorizontale*sin(angleHorizontal);

    calculVise();
}

void CameraVolante::droite(){
    x+=vitesse*cos(angleHorizontal+M_PI/2);
    z+=vitesse*sin(angleHorizontal+M_PI/2);

    calculVise();
}

void CameraVolante::gauche(){
    x+=vitesse*cos(angleHorizontal-M_PI/2);
    z+=vitesse*sin(angleHorizontal-M_PI/2);

    calculVise();
}


void CameraVolante::monte(){
    y+=vitesse;

    calculVise();
}

void CameraVolante::descend(){
    y-=vitesse;

    calculVise();
}

void CameraVolante::tourne(double horizontal, double vertical){
    angleHorizontal+=deg2rad(sensibilite*horizontal);
    angleVertical-=deg2rad(sensibilite*vertical);
    while(angleHorizontal>=M_PI) angleHorizontal-=2*M_PI;
    while(angleHorizontal<-M_PI) angleHorizontal+=2*M_PI;
    while(angleVertical>M_PI/2) angleVertical-=0.0001;
    while(angleVertical<-M_PI/2) angleVertical+=0.0001;

    calculVise();
}

void CameraVolante::affiche(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z, xVise, yVise, zVise, 0, 1, 0);

    if(debug){
        glDepthFunc(GL_ALWAYS);
        glLineWidth(2);
        glBegin(GL_LINES);
            glColor3ub(255,0,0); glVertex3d(xVise,yVise,zVise); glVertex3d(xVise+0.1,yVise,zVise);
            glColor3ub(0,255,0); glVertex3d(xVise,yVise,zVise); glVertex3d(xVise,yVise+0.1,zVise);
            glColor3ub(0,0,255); glVertex3d(xVise,yVise,zVise); glVertex3d(xVise,yVise,zVise+0.1);
        glEnd();
        glLineWidth(1);
        glDepthFunc(GL_LESS);
    }
}

void CameraVolante::gestionEvenements(Input& input){
    if(input.key[TOUCHE_AVANT]){
        avance();
    }
    if(input.key[TOUCHE_ARRIERE]){
        recule();
    }
    if(input.key[TOUCHE_DROITE]){
        droite();
    }
    if(input.key[TOUCHE_GAUCHE]){
        gauche();
    }
    if(input.key[TOUCHE_HAUT]){
        monte();
    }
    if(input.key[TOUCHE_BAS]){
        descend();
    }
    if(input.mouseXRel || input.mouseYRel){
        tourne(input.mouseXRel, input.mouseYRel);
    }
}


void CameraVolante::calculVise(){
    double vitesseHorizontale=cos(angleVertical);
    xVise=x+vitesseHorizontale*cos(angleHorizontal);
    yVise=y+sin(angleVertical);
    zVise=z+vitesseHorizontale*sin(angleHorizontal);

    joueur.pickingBloc();
}

