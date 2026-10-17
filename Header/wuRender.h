#ifndef WURENDER_H
#define WURENDER_H
#include "SDL3/SDL.h"
#include "wu2D_Graphics.h"
#include <vector>
using std::vector;

class wuRender {
private:
    SDL_Renderer* renderer{ nullptr };
public:
    void ON(SDL_Window* window);
    void OFF();

    void Clear();
    void Present(wu2D_Buffer& buff);
};

#endif // WURENDER_H
// [=]<-------------------------------------------------------------->[=]