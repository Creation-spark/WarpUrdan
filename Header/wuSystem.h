#ifndef WUSYSTEM_H
#define WUSYSTEM_H
#include <SDL3/SDL.h>
#include <iostream>
using namespace std;

#include "wuType.h"

class wuSystem {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    // Destructor
    ~wuSystem();
    // Get
    SDL_Window* G_Window();
    SDL_Renderer* G_Renderer();
    // Init
    void In_Video();
    // Create
    void Cr_Window(string gTitle, Int2 gSize, SDL_WindowFlags gFlags);
    void Cr_Renderer();
};

#endif // WUSYSTEM_H

// [============================->{ ... }<-============================]