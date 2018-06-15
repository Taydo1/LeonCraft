#ifndef PERSO_H
#define PERSO_H

#define G 9.81


class Perso
{
    public:
        Perso();
        virtual ~Perso();
        void affiche();

    protected:
        double aX, aY, aZ,
               vX, vY, vZ,
               x,  y,  z;

};

#endif // PERSO_H
