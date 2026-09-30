#include "wuSpace.h"
// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Figure }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]

Figure::Figure() {

}
Figure::Figure(Figure_TYPE Type, Int2 Pos, UInt2 Size, Pixel Color, int Turn) {
    type = Type;
    pos = Pos;
    size = Size;
    color = Color;
    turn = Turn;
}

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Draw_Buffer }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]

Vec<Figure>& Draw_Buffer::G_Layer(int layer) {
    switch (layer) {
    case 2: return OverUI;
    case 1: return UI;
    case 0: return UnderUI;
    }
    static Vec<Figure> empty_layer;
    return empty_layer;
}
// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Render }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]

Render::Render() {
    // Empty one
}
Render::Render(SDL_Window* window, Draw_Buffer* gBuff) :
    renderer(SDL_CreateRenderer(window, NULL)),
    buff(gBuff) {
    if (renderer == nullptr) {
        SDL_Log("Renderer failed");
        exit(0);
    }
}
Render::~Render() {
    SDL_DestroyRenderer(renderer);
}

// [=]<------------------------------------------------------------->[=]

void Render::Clear_Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}
void Render::Present_Render() {
    SDL_RenderPresent(renderer);
}

// [=]<------------------------------------------------------------->[=]

void Render::Render_Figures() {
    for (int i{ 0 };i < 3;i++) { // Through layers
        Vec<Figure>& lay = buff->G_Layer(i);
        for (int j{ 0 }; j < lay.Size();j++) { // Through figures
            Figure* fig = &lay[j];
            switch (fig->type) {
            case FIGURE_EMPTY: {
                continue;
            }
            case FIGURE_TRINGLE: {
                break;
            }
            case FIGURE_RECTENGLE: {
                int half_w = fig->size.x / 2;
                int half_h = fig->size.y / 2;
                SDL_Vertex vertex[4] = {
                    { (float)(fig->pos.x - half_w),(float)(fig->pos.y - half_h) }, // ^<
                    { (float)(fig->pos.x + half_w),(float)(fig->pos.y - half_h) }, // ^>
                    { (float)(fig->pos.x - half_w),(float)(fig->pos.y + half_h) }, // _<
                    { (float)(fig->pos.x + half_w),(float)(fig->pos.y + half_h) }, // _>
                };
                int indices[6] = { 0,1,2, 1,3,2 };

                SDL_FColor col = {
                    fig->color.r / 255.0f,
                    fig->color.g / 255.0f,
                    fig->color.b / 255.0f,
                    fig->color.a / 255.0f,
                };
                for (int v{ 0 };v < 4;v++) {
                    vertex[v].color = col;
                }

                SDL_RenderGeometry(renderer, NULL, vertex, 4, indices, 6);
                break;
            }
            case FIGURE_CIRCL: {
                
                break;
            }
            case FIGURE_POLYGONE: {
                break;
            }
            }// Switch END
        }
    }
}

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ wuSpace }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]

wuSpace::wuSpace()
  : window(SDL_CreateWindow("None", 100, 100, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS)),
    buff(new Draw_Buffer),
    render(window, buff ) {
        if (window == nullptr) {
            SDL_Log("Window failed");
        exit(0);
    }
}
wuSpace::~wuSpace() {
    delete buff;

    SDL_DestroyWindow(window);
}

// [=]<------------------------------------------------------------->[=]

void wuSpace::Set_LayerSize(int layer, int size) {
    buff->G_Layer(layer).Resize(size);
}
Figure* wuSpace::Get_Figure(int layer, int id) {
    return &buff->G_Layer(layer)[id];
    return nullptr;
}

// [=]<------------------------------------------------------------->[=]

void wuSpace::Render_Draw_Buffer() {
    render.Clear_Render();

    render.Render_Figures();

    render.Present_Render();
}

// [=]<------------------------------------------------------------->[=]

void wuSpace::ProgWin_Title(std::string Title) {
    SDL_SetWindowTitle(window, Title.c_str());
}
void wuSpace::ProgWin_Pos(int X, int Y) {
    SDL_SetWindowPosition(window, X, Y);
}
void wuSpace::ProgWin_Size(int Withd, int Hight) {
    SDL_SetWindowSize(window, Withd, Hight);
}