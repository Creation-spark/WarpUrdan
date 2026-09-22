#include "wuCicle.h"

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Event }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ Get }<-============================]
bool Event::G_NewEvent() {
    return SDL_PollEvent(&event);
}
// [============================->{ Processing }<-============================]
wuResult Event::Pr_Program() {
    switch (event.type) {
    case SDL_EVENT_QUIT: {
        return WU_SUCCESS;
    }
    }
    return WU_NONE;
}
wuResult Event::Pr_Keyboard() {
    switch (event.key.key) {
    case SDLK_ESCAPE: {
        return WU_SUCCESS;
    }
    }
    return WU_NONE;
}
wuResult Event::Pr_Mous() {
    return WU_NONE;
}
bool Event::Pr_Events() {
    while (G_NewEvent()) {
        result = Pr_Program();
        if (result != WU_NONE) break;
        result = Pr_Keyboard();
        if (result != WU_NONE) break;
        result = Pr_Mous();
        if (result != WU_NONE) break;
    }

    if (result != WU_NONE) return true;
    return false;
}

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Frame }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ Set }<-============================]
void Frame::S_Rate(int rate) {
    expected = 1000 / rate;
}
void Frame::S_Start() {
    start = SDL_GetTicks();
}
void Frame::S_End() {
    end = SDL_GetTicks();
}
void Frame::S_Deley() {
    
    cicle = end - start;
    if (cicle < expected) {
        SDL_Delay(expected - cicle);
    }
    cout << cicle << "ms" << endl;
}

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Render }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ Destructor }<-============================]
Render::~Render() {
    delete buff;
}
// [============================->{ Set }<-============================]
void Render::S_Renderer(SDL_Renderer* gRenderer) {
    renderer = gRenderer;
}
void Render::S_Objects_Buffer(wuObject_Buffer* gBuff) {
    if (buff != nullptr) {
        delete buff;
        buff = gBuff;
    }
    else {
        buff = gBuff;
    }
}
// [============================->{ Render }<-============================]
void Render::R_ClearSurface(Pixel color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}
void Render::R_Figures() {
    for (int i{ 0 };i < buff->figure_count;i++) {
        Figure fig = buff->figures[i];
        SDL_SetRenderDrawColor(renderer, fig.color.r, fig.color.g, fig.color.b, fig.color.a);
        if (fig.type == FIGURE_RECT) {
            rect = { (float)fig.pos.x, (float)fig.pos.y, (float)fig.size.x, (float)fig.size.y };
            if (fig.angle == 0) {
                SDL_RenderFillRect(renderer, &rect);
            }
            else {
                // Still empty
            }
        }
    }
}
void Render::R_Objects() {
    R_Figures();
}
void Render::R_Present() {
    SDL_RenderPresent(renderer);
}