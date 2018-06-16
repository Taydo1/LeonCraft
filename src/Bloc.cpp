#include "Bloc.h"


extern vector<Bloc*> carte;

int Bloc::compteurId=0;

Bloc::Bloc(double x, double y, double z, double w, double h, double d, GLuint texture):
    x(x),
    y(y),
    z(z),
    w(w),
    h(h),
    d(d),
    texture(texture)
{
    for(int i=0;i<6;i++){
        id[i]=compteurId+i;

        couleurs[i][0]=(id[0]&16711680)/65535;
        couleurs[i][1]=(id[0]&65280)/256;
        couleurs[i][2]=(id[0]&255)+i;
    }
    compteurId+=6;
}

Bloc::Bloc(Bloc bloc2, int cote):
    x(bloc2.x),
    y(bloc2.y),
    z(bloc2.z),
    w(bloc2.w),
    h(bloc2.h),
    d(bloc2.d),
    texture(bloc2.texture)
{
    for(int i=0;i<6;i++){
        id[i]=compteurId+i;

        couleurs[i][0]=(id[0]&16711680)/65535;
        couleurs[i][1]=(id[0]&65280)/256;
        couleurs[i][2]=(id[0]&255)+i;
    }
    compteurId+=6;

    switch(cote){
    case 0:
        z--;
        break;
    case 1:
        z++;
        break;
    case 2:
        x--;
        break;
    case 3:
        x++;
        break;
    case 4:
        y--;
        break;
    case 5:
        y++;
        break;
    }
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
    for(unsigned int i=0;i<carte.size();i++){
        if(carte[i]==this){
            carte.erase(carte.begin()+i);
        }
    }
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
        //dessous
        glTexCoord2d (0,1); glVertex3d(x, y, z);
        glTexCoord2d (0,0); glVertex3d(x, y, z+d);
        glTexCoord2d (1,0); glVertex3d(x+w, y, z+d);
        glTexCoord2d (1,1); glVertex3d(x+w, y, z);
        //dessus
        glTexCoord2d (0,1); glVertex3d(x+w, y+h, z);
        glTexCoord2d (0,0); glVertex3d(x+w, y+h, z+d);
        glTexCoord2d (1,0); glVertex3d(x, y+h, z+d);
        glTexCoord2d (1,1); glVertex3d(x, y+h, z);
    glEnd();
}

void Bloc::affichePicking(){
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
        //devant
        glColor3ub(couleurs[0][0], couleurs[0][1], couleurs[0][2]);
            glVertex3d(x+w, y, z);
            glVertex3d(x+w, y+h, z);
            glVertex3d(x, y+h, z);
            glVertex3d(x, y, z);
        //derriere
        glColor3ub(couleurs[1][0], couleurs[1][1], couleurs[1][2]);
            glVertex3d(x, y, z+d);
            glVertex3d(x, y+h, z+d);
            glVertex3d(x+w, y+h, z+d);
            glVertex3d(x+w, y, z+d);
        //droite
        glColor3ub(couleurs[2][0], couleurs[2][1], couleurs[2][2]);
            glVertex3d(x, y, z);
            glVertex3d(x, y+h, z);
            glVertex3d(x, y+h, z+d);
            glVertex3d(x, y, z+d);
        //gauche
        glColor3ub(couleurs[3][0], couleurs[3][1], couleurs[3][2]);
            glVertex3d(x+w, y, z+d);
            glVertex3d(x+w, y+h, z+d);
            glVertex3d(x+w, y+h, z);
            glVertex3d(x+w, y, z);
        //dessous
        glColor3ub(couleurs[4][0], couleurs[4][1], couleurs[4][2]);
            glVertex3d(x, y, z);
            glVertex3d(x, y, z+d);
            glVertex3d(x+w, y, z+d);
            glVertex3d(x+w, y, z);
        //dessus
        glColor3ub(couleurs[5][0], couleurs[5][1], couleurs[5][2]);
            glVertex3d(x+w, y+h, z);
            glVertex3d(x+w, y+h, z+d);
            glVertex3d(x, y+h, z+d);
            glVertex3d(x, y+h, z);
    glEnd();
}

void Bloc::surligneCote(int idCote){
    glBegin(GL_LINE_LOOP);
    switch(idCote){
    case 0:
        glColor3ub(couleurs[0][0], couleurs[0][1], couleurs[0][2]);
            glVertex3d(x+w, y, z);
            glVertex3d(x+w, y+h, z);
            glVertex3d(x, y+h, z);
            glVertex3d(x, y, z);
        break;
    case 1:
        glColor3ub(couleurs[1][0], couleurs[1][1], couleurs[1][2]);
            glVertex3d(x, y, z+d);
            glVertex3d(x, y+h, z+d);
            glVertex3d(x+w, y+h, z+d);
            glVertex3d(x+w, y, z+d);
        break;
    case 2:
        glColor3ub(couleurs[2][0], couleurs[2][1], couleurs[2][2]);
            glVertex3d(x, y, z);
            glVertex3d(x, y+h, z);
            glVertex3d(x, y+h, z+d);
            glVertex3d(x, y, z+d);
        break;
    case 3:
        glColor3ub(couleurs[3][0], couleurs[3][1], couleurs[3][2]);
            glVertex3d(x+w, y, z+d);
            glVertex3d(x+w, y+h, z+d);
            glVertex3d(x+w, y+h, z);
            glVertex3d(x+w, y, z);
        break;
    case 4:
        glColor3ub(couleurs[4][0], couleurs[4][1], couleurs[4][2]);
            glVertex3d(x, y, z);
            glVertex3d(x, y, z+d);
            glVertex3d(x+w, y, z+d);
            glVertex3d(x+w, y, z);
        break;
    case 5:
        glColor3ub(couleurs[5][0], couleurs[5][1], couleurs[5][2]);
            glVertex3d(x+w, y+h, z);
            glVertex3d(x+w, y+h, z+d);
            glVertex3d(x, y+h, z+d);
            glVertex3d(x, y+h, z);
        break;
    }
    glEnd();
}
