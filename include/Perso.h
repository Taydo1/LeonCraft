#ifndef PERSO_H
#define PERSO_H

#define G 9.81

#include "Bloc.h"
#include "Input.h"


class Perso
{
    public:
        Perso();
        virtual ~Perso();
        void affiche();
        void pickingBloc();
        void detruitBloc();
        void placeBloc();
        void gestionEvenements(Input& input);

        Bloc* getBlocVise();
        int getCoteVise();

    protected:
        double aX, aY, aZ,
               vX, vY, vZ,
               x,  y,  z;
        Bloc* blocVise=NULL;
        int coteVise=0;
};

#endif // PERSO_H
