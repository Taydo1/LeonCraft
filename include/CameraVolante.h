#ifndef CAMERAVOLANTE_H
#define CAMERAVOLANTE_H

#include "Input.h"


class CameraVolante
{
    public:
        CameraVolante(double x, double y, double z);
        ~CameraVolante();
        void avance();
        void recule();
        void droite();
        void gauche();
        void monte();
        void descend();
        void tourne(double horizontal, double vertical);
        void affiche();
        void gestionEvenements(Input& input);

    protected:
        void calculVise();

        double x, y, z, xVise, yVise, zVise, angleHorizontal, angleVertical;
        static constexpr double vitesse=0.05,
                            sensibilite=0.6;

};

#endif // CAMERA_H
