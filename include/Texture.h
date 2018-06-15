#ifndef TEXTURE_H
#define TEXTURE_H

#include "Constantes.h"
class Texture
{
    public:
        Texture(string fichierImage);
        Texture();
        ~Texture();
        bool charger(string fichierImage);
        GLuint getID() const;
        void setFichierImage(const string &fichierImage);


    protected:
        GLuint id;
        string fichierImage;
};

#endif // TEXTURE_H
