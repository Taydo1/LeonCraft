#include "Input.h"

#include"Constantes.h"

Input::Input():
    quit(false),
    mouseButton({0,0,0,0,0}),
    mouseX(0),
    mouseY(0),
    mouseXRel(0),
    mouseYRel(0),
    mouseWheelX(0),
    mouseWheelY(0)
{
    for(int i=0;i<SDL_NUM_SCANCODES;i++){
        key[i]=0;
    }
}

void Input::updateInput(SDL_Event& evenements){
    mouseXRel=0;
    mouseYRel=0;
    while(SDL_PollEvent(&evenements)){
        switch(evenements.type){
        case SDL_MOUSEMOTION:
            mouseX=evenements.motion.x;
            mouseY=evenements.motion.y;
            mouseXRel=evenements.motion.xrel;
            mouseYRel=evenements.motion.yrel;
            break;
        case SDL_KEYDOWN:
            if(!evenements.key.repeat) key[evenements.key.keysym.scancode]=true;
            break;
        case SDL_KEYUP:
            if(!evenements.key.repeat) key[evenements.key.keysym.scancode]=false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            mouseButton[evenements.button.button]=true;
            break;
        case SDL_MOUSEBUTTONUP:
            mouseButton[evenements.button.button]=false;
            break;
        case SDL_MOUSEWHEEL:
            mouseWheelX=evenements.wheel.x;
            mouseWheelY=evenements.wheel.y;
            break;
        case SDL_QUIT:
            quit=true;
        }
    }
}
