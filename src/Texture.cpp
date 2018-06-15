#include "Texture.h"

Texture::Texture(string fichierImage) : id(0), fichierImage(fichierImage)
{
    charger(fichierImage);
}

Texture::Texture() : id(0)
{

}


Texture::~Texture()
{

}


bool Texture::charger(string fichierImage)
{
    this->fichierImage=fichierImage;
    // Chargement de l'image dans une surface SDL
    SDL_Surface *imageSDL = IMG_Load(("images/"+fichierImage).c_str());

    if(imageSDL == 0)
    {
        cout << "Erreur : " << SDL_GetError() << endl;
        return false;
    }


    // Génération de l'ID
    glGenTextures(1, &id);


    // Verrouillage
    glBindTexture(GL_TEXTURE_2D, id);


    // Format de l'image
    GLenum formatInterne(0);
    GLenum format(0);


    // Détermination du format et du format interne pour les images à 3 composantes
    if(imageSDL->format->BytesPerPixel == 3)
    {
        // Format interne
        formatInterne = GL_RGB;
        format = GL_RGB;
    }


    // Détermination du format et du format interne pour les images à 4 composantes
    else if(imageSDL->format->BytesPerPixel == 4)
    {
        // Format interne
        formatInterne = GL_RGBA;
        format = GL_RGBA;
    }


    // Dans les autres cas, on arrête le chargement
    else
    {
        std::cout << "Erreur, format interne de l'image inconnu" << std::endl;
        SDL_FreeSurface(imageSDL);
        return false;
    }


    // Copie des pixels
    glTexImage2D(GL_TEXTURE_2D, 0, formatInterne, imageSDL->w, imageSDL->h, 0, format, GL_UNSIGNED_BYTE, imageSDL->pixels);


    // Application des filtres
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    // Déverrouillage
    glBindTexture(GL_TEXTURE_2D, 0);


    // Fin de la méthode
    SDL_FreeSurface(imageSDL);
    return true;
}


GLuint Texture::getID() const
{
    return id;
}


void Texture::setFichierImage(const string &fichierImage)
{
    this->fichierImage = fichierImage;
}
