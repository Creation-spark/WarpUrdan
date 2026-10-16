// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Includes }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]
#include "wuRender.h"
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Render }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

void wuRender::ON(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        SDL_Log("System constr render failed");
    }
}
void wuRender::OFF() {
    SDL_DestroyRenderer(renderer);
}
// [=]<-------------------------------------------------------------->[=]

void wuRender::Clear() {
    SDL_SetRenderDrawColor(renderer, 17, 0, 40, 255);
    SDL_RenderClear(renderer);
}
void wuRender::Present(wu2D_Buffer& buff) {
    buff.CollectGeometry();
    
    SDL_RenderGeometry(renderer, NULL,
        buff.vertexes.data(), buff.vertexes.size(),
        buff.indices.data(), buff.indices.size()
    );
    SDL_RenderPresent(renderer);
}