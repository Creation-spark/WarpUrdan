#ifndef WUOBJECTS_H
#define WUOBJECTS_H
#include <SDL3/SDL.h>
#include <iostream>
using namespace std;

#include "wuType.h"
#include "wuObjects_Buffer.h"

class Program_Window {
private:
    SDL_Window* window{ nullptr };
    SDL_WindowFlags flags{0};

    string title{ "" };
    Int2 pos{ 0,0 };
    Int2 size{ 0,0 };
public:
    // Set
    void S_Window(SDL_Window* gWindow);
    void S_Title(string title);
    void S_Pos(Int2 gPos);
    void S_Size(Int2 gSize);
};

class wuObjects {
private:
    Figure* figures{ nullptr };
    int figure_count{ 0 };
public:
    // Destructor
    ~wuObjects();
    // Objects
    Program_Window prgrm_win;
    // Create
    void Cr_FigureArray(int amount);
    // Get
    Figure* G_FigureArray();
    wuObject_Buffer* G_ObjectBuffer();
    // Add
    void Add_Figure(Figure_Type gType, Pixel gColor, Int2 gPos, Int2 gSize, int gAngle);
};

#endif // WUOBJECTS_H

// [============================->{ ... }<-============================]