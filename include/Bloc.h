#ifndef BLOC_H
#define BLOC_H

#include "Constantes.h"

class Bloc
{
    public:
        Bloc(double x, double y, double z, double w, double h, double d, GLuint texture);
        Bloc();
        virtual ~Bloc();
        virtual void affiche();

    protected:
        double x, y, z, w, h, d;
        GLuint texture;

};

#endif // BLOC_H
