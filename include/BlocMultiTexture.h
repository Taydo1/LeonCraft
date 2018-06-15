#ifndef BLOCMULTITEXTURE_H
#define BLOCMULTITEXTURE_H

#include <Bloc.h>


class BlocMultiTexture : public Bloc
{
    public:
        BlocMultiTexture(double x, double y, double z, double w, double h, double d, GLuint textureAvant, GLuint textureArriere, GLuint textureDroite, GLuint textureGauche, GLuint textureDessus, GLuint textureDessous);
        BlocMultiTexture(double x, double y, double z, double w, double h, double d, GLuint textureCote, GLuint textureDessus, GLuint textureDessous);
        BlocMultiTexture();
        virtual ~BlocMultiTexture();
        virtual void affiche();

    protected:
        GLuint textureArriere,
               textureDroite,
               textureGauche,
               textureDessus,
               textureDessous;
};

#endif // BLOCMULTITEXTURE_H
