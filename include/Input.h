#ifndef INPUT_H
#define INPUT_H

#include "Constantes.h"


class Input
{
    public:
        Input();

        void updateInput(SDL_Event& evenements);

        bool quit;
        bool key[SDL_NUM_SCANCODES];
        bool mouseButton[5];
        int mouseX,
            mouseY,
            mouseXRel,
            mouseYRel,

            mouseWheelX,
            mouseWheelY;

};

#endif // INPUT_H
