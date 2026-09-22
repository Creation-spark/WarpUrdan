#include "wuSystem.h"

// [============================->{ Destructor }<-============================]
wuSystem::~wuSystem() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}
// [============================->{ Get }<-============================]
SDL_Window* wuSystem::G_Window() {
    return window;
}
SDL_Renderer* wuSystem::G_Renderer() {
    return renderer;
}
// [============================->{ Init }<-============================]
void wuSystem::In_Video() {
    if (SDL_APP_FAILURE == SDL_Init(SDL_INIT_VIDEO)) {
        cout << "Video failed" << endl;
    }
}
// [============================->{ Create }<-============================]
void wuSystem::Cr_Window(string gTitle, Int2 gSize, SDL_WindowFlags gFlags) {
    window = SDL_CreateWindow(gTitle.c_str(), gSize.x, gSize.y, gFlags);
    if (window == nullptr) {
        cout << "window failed" << endl;
    }
}
void wuSystem::Cr_Renderer() {
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        cout << "renderer failed" << endl;
    }
}