#include "BlocMultiTexture.h"

//Faces toutes differentes
BlocMultiTexture::BlocMultiTexture(double x, double y, double z, double w, double h, double d, GLuint textureAvant, GLuint textureArriere, GLuint textureDroite, GLuint textureGauche, GLuint textureDessus, GLuint textureDessous):
    Bloc(x,y,z,w,h,d,textureAvant),
    textureArriere(textureArriere),
    textureDroite(textureDroite),
    textureGauche(textureGauche),
    textureDessus(textureDessus),
    textureDessous(textureDessous)
{
    //ctor
}

//Cotes identiques
BlocMultiTexture::BlocMultiTexture(double x, double y, double z, double w, double h, double d, GLuint textureCote, GLuint textureDessus, GLuint textureDessous):
    Bloc(x,y,z,w,h,d,textureCote),
    textureArriere(textureCote),
    textureDroite(textureCote),
    textureGauche(textureCote),
    textureDessus(textureDessus),
    textureDessous(textureDessous)
{
    //ctor
}

BlocMultiTexture::BlocMultiTexture():
    Bloc(),
    textureArriere(0),
    textureDroite(0),
    textureGauche(0),
    textureDessus(0),
    textureDessous(0)
{
    //ctor
}

BlocMultiTexture::~BlocMultiTexture()
{
    //dtor
}

void BlocMultiTexture::affiche(){
    glColor3ub(255,255,255);

    //devant
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
        glTexCoord2d (0,1); glVertex3d(x+w, y, z);
        glTexCoord2d (0,0); glVertex3d(x+w, y+h, z);
        glTexCoord2d (1,0); glVertex3d(x, y+h, z);
        glTexCoord2d (1,1); glVertex3d(x, y, z);
    glEnd();

    //derriere
    glBindTexture(GL_TEXTURE_2D, textureArriere);
    glBegin(GL_QUADS);
        glTexCoord2d (0,1); glVertex3d(x, y, z+d);
        glTexCoord2d (0,0); glVertex3d(x, y+h, z+d);
        glTexCoord2d (1,0); glVertex3d(x+w, y+h, z+d);
        glTexCoord2d (1,1); glVertex3d(x+w, y, z+d);
    glEnd();

    //droite
    glBindTexture(GL_TEXTURE_2D, textureDroite);
    glBegin(GL_QUADS);
        glTexCoord2d (0,1); glVertex3d(x, y, z);
        glTexCoord2d (0,0); glVertex3d(x, y+h, z);
        glTexCoord2d (1,0); glVertex3d(x, y+h, z+d);
        glTexCoord2d (1,1); glVertex3d(x, y, z+d);
    glEnd();

    //gauche
    glBindTexture(GL_TEXTURE_2D, textureGauche);
    glBegin(GL_QUADS);
        glTexCoord2d (0,1); glVertex3d(x+w, y, z+d);
        glTexCoord2d (0,0); glVertex3d(x+w, y+h, z+d);
        glTexCoord2d (1,0); glVertex3d(x+w, y+h, z);
        glTexCoord2d (1,1); glVertex3d(x+w, y, z);
    glEnd();

    //dessus
    glBindTexture(GL_TEXTURE_2D, textureDessus);
    glBegin(GL_QUADS);
        glTexCoord2d (0,1); glVertex3d(x+w, y+h, z);
        glTexCoord2d (0,0); glVertex3d(x+w, y+h, z+d);
        glTexCoord2d (1,0); glVertex3d(x, y+h, z+d);
        glTexCoord2d (1,1); glVertex3d(x, y+h, z);
    glEnd();

    //dessous
    glBindTexture(GL_TEXTURE_2D, textureDessous);
    glBegin(GL_QUADS);
        glTexCoord2d (0,1); glVertex3d(x, y, z);
        glTexCoord2d (0,0); glVertex3d(x, y, z+d);
        glTexCoord2d (1,0); glVertex3d(x+w, y, z+d);
        glTexCoord2d (1,1); glVertex3d(x+w, y, z);
    glEnd();
}
