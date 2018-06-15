#include "Bloc.h"


Bloc::Bloc(double x, double y, double z, double w, double h, double d, GLuint texture):
    x(x),
    y(y),
    z(z),
    w(w),
    h(h),
    d(d),
    texture(texture)
{
    //ctor
}

Bloc::Bloc():
    x(0),
    y(0),
    z(0),
    w(0),
    h(0),
    d(0),
    texture(0)
{
    //ctor
}

Bloc::~Bloc()
{
    //dtor
}

void Bloc::affiche(){
    glBindTexture(GL_TEXTURE_2D, texture);
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        //devant
        glTexCoord2d (0,1); glVertex3d(x+w, y, z);
        glTexCoord2d (0,0); glVertex3d(x+w, y+h, z);
        glTexCoord2d (1,0); glVertex3d(x, y+h, z);
        glTexCoord2d (1,1); glVertex3d(x, y, z);
        //derriere
        glTexCoord2d (0,1); glVertex3d(x, y, z+d);
        glTexCoord2d (0,0); glVertex3d(x, y+h, z+d);
        glTexCoord2d (1,0); glVertex3d(x+w, y+h, z+d);
        glTexCoord2d (1,1); glVertex3d(x+w, y, z+d);
        //droite
        glTexCoord2d (0,1); glVertex3d(x, y, z);
        glTexCoord2d (0,0); glVertex3d(x, y+h, z);
        glTexCoord2d (1,0); glVertex3d(x, y+h, z+d);
        glTexCoord2d (1,1); glVertex3d(x, y, z+d);
        //gauche
        glTexCoord2d (0,1); glVertex3d(x+w, y, z+d);
        glTexCoord2d (0,0); glVertex3d(x+w, y+h, z+d);
        glTexCoord2d (1,0); glVertex3d(x+w, y+h, z);
        glTexCoord2d (1,1); glVertex3d(x+w, y, z);
        //dessus
        glTexCoord2d (0,1); glVertex3d(x+w, y+h, z);
        glTexCoord2d (0,0); glVertex3d(x+w, y+h, z+d);
        glTexCoord2d (1,0); glVertex3d(x, y+h, z+d);
        glTexCoord2d (1,1); glVertex3d(x, y+h, z);
        //dessous
        glTexCoord2d (0,1); glVertex3d(x, y, z);
        glTexCoord2d (0,0); glVertex3d(x, y, z+d);
        glTexCoord2d (1,0); glVertex3d(x+w, y, z+d);
        glTexCoord2d (1,1); glVertex3d(x+w, y, z);
    glEnd();

}
