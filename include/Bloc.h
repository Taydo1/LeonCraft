#ifndef BLOC_H
#define BLOC_H

#include "Constantes.h"

class Bloc
{
    public:
        Bloc(double x, double y, double z, double w, double h, double d, GLuint texture);
        Bloc(Bloc bloc2, int cote);
        Bloc();
        virtual ~Bloc();
        virtual void affiche();
        void affichePicking();
        void surligneCote(int idCote);
        int id[6];
        static int compteurId;

    protected:
        double x, y, z, w, h, d;
        int couleurs[6][3] ;
        GLuint texture;

};
#endif // BLOC_H
