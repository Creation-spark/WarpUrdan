#ifndef WUCICLE_H
#define WUCICLE_H
#include <SDL3/SDL.h>
#include <iostream>
using namespace std;

#include "wuType.h"
#include "wuObjects_Buffer.h"

class Event {
private:
    SDL_Event event;
    wuResult result{ WU_NONE };
public:
    // Get
    bool G_NewEvent();
    // Processing
    wuResult Pr_Program();
    wuResult Pr_Keyboard();
    wuResult Pr_Mous();
    bool Pr_Events();
};

class Frame {
private:
    // All in milliseconds
    Uint64 expected{ 0 };
    Uint64 start{ 0 };
    Uint64 end{ 0 };
    Uint64 cicle{ 0 };
public:
    // Set
    void S_Rate(int rate);
    void S_Start();
    void S_End();
    void S_Deley();
};

class Render {
private:
    SDL_Renderer* renderer{ nullptr };
    SDL_FRect rect;
    wuObject_Buffer* buff{ nullptr };
public:
    ~Render();
    // Set
    void S_Renderer(SDL_Renderer* ren);
    void S_Objects_Buffer(wuObject_Buffer* gBuff);
    // Render
    void R_ClearSurface(Pixel color);
    void R_Figures();
    void R_Objects();
    void R_Present();
};

class wuCicle {
public:
    // Objects
    Event event;
    Frame frame;
    Render render;
};

#endif // WUCICLE_H

// [============================->{ ... }<-============================]