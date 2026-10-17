// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Includes }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

#include "wu2D_Graphics.h"

// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Figure }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

Figure::Figure() {
    
}
Figure::Figure(Figure_TYPE gType, Float2 gPos, Float2 gSize, Pixel gColor, int gTurn) {
    S_Type()  = gType;
    S_Pos()   = gPos;
    S_Size()  = gSize;
    S_Color() = gColor;
    S_Turn()  = gTurn;
}
// [=]<-------------------------------------------------------------->[=]

Figure_TYPE& Figure::S_Type()  { changed_Type = true;     return type; }
Float2&      Figure::S_Pos()   { changed_XY_WH = true; return pos; }
Float2&      Figure::S_Size()  { changed_XY_WH = true; return size; }
Pixel&       Figure::S_Color() { changed_Color = true;    return color; }
int&         Figure::S_Turn()  { changed_XY_WH = true; return turn; }
// [=]<-------------------------------------------------------------->[=]

const Figure_TYPE& Figure::G_Type()  { return type; }
const Float2&      Figure::G_Pos()   { return pos; }
const Float2&      Figure::G_Size()  { return size; }
const Pixel&       Figure::G_Color() { return color; }
const int&         Figure::G_Turn()  { return turn; }
// [=]<-------------------------------------------------------------->[=]

void Figure::Recalculate() {
    switch (type) {
    case FIGURE_TRIANGEL: {
        if (changed_Type) {
            vertexes.resize(3);
            indices.resize(3);

            vertexes = { { 0,-0.5 },{ 0.5,0.5 },{ -0.5,0.5 } };
            indices = { 0,2,1 };
        }
        if (changed_XY_WH) {
            float W = 0.5 * size.x;
            float H = 0.5 * size.y;
            vertexes[0] = { 0,-H + pos.y };
            vertexes[1] = { W + pos.x, H + pos.y };
            vertexes[2] = { -W + pos.x, H + pos.y };
        }
        if (changed_Color) {
            float sub = 1.0f / 255.0f;
            SDL_FColor col{ color.r * sub,color.g * sub,color.b * sub,color.a * sub, };
            for (int i{ 0 };i < 3;i++) {
                vertexes[i].color = col;
            }
        }
        
        break;
    }
    case FIGURE_RECTENGLE: {
        if (changed_Type) {
            vertexes.resize(4);
            indices.resize(6);

            vertexes = { { -0.5,-0.5 },{ 0.5,-0.5 },{ 0.5,0.5 },{ -0.5,0.5 } };
            indices = { 0,3,1, 1,3,2 };
        }
        if (changed_XY_WH) {
            float W = 0.5 * size.x;
            float H = 0.5 * size.y;
            vertexes[0] = { -W + pos.x,-H + pos.y };
            vertexes[1] = { W + pos.x, -H + pos.y };
            vertexes[2] = { W + pos.x, H + pos.y };
            vertexes[3] = { -W + pos.x, H + pos.y };
        }
        if (changed_Color) {
            float sub = 1.0f / 255.0f;
            SDL_FColor col{ color.r * sub,color.g * sub,color.b * sub,color.a * sub, };
            for (int i{ 0 };i < 4;i++) {
                vertexes[i].color = col;
            }
        }
        break;
    }
    default:

        break;
    }

    changed_Type = false;
    changed_XY_WH = false;
    changed_Color = false;
}
void Figure::G_Geometry(vector<SDL_Vertex>& gVertexes, vector<int>& gIndices, int& gLast_indice) {
    Recalculate();

    for (int i{ 0 };i < vertexes.size();i++) {
        gVertexes.push_back(vertexes[i]);
    }
    for (int i{ 0 };i < indices.size();i++) {
        gIndices.push_back(indices[i] + gLast_indice);
    }
    switch (type) {
    case FIGURE_TRIANGEL: {
        gLast_indice += 3;
        break;
    }
    case FIGURE_RECTENGLE: {
        gLast_indice += 4;
        break;
    }
    default:
        break;
    }
}

// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Window }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

Window::Window() {
    
}
Window::Window(Float2 gPos, Float2 gSize, float gBor_thick) {
    S_Pos()       = gPos;
    S_Size()      = gSize;
    S_Bor_Thick() = gBor_thick;

    Create_Frame();

    created = true;
}
// [=]<------------------------------------------------------------->[=]

void Window::Create_Frame() {
    figs.resize(5);
    float half_w{ (size.x - bor_thick) * 0.5f };
    float half_h{ (size.y - bor_thick) * 0.5f };
    // Background
    figs[0] = Figure{ FIGURE_RECTENGLE,Float2{ pos.x,pos.y },Float2{ size.x ,size.y },{255,0,120,255},0 };
    // Borders
    figs[1] = Figure{ FIGURE_RECTENGLE,Float2{ pos.x - half_w, pos.y },Float2{ bor_thick, size.y },{ 80,0,120,255 },0 };
    figs[2] = Figure{ FIGURE_RECTENGLE,Float2{ pos.x + half_w, pos.y },Float2{ bor_thick, size.y },{ 80,0,120,255 },0 };
    figs[3] = Figure{ FIGURE_RECTENGLE,Float2{ pos.x,pos.y - half_h }, Float2{ size.x ,bor_thick },{ 80,0,120,255 },0 };
    figs[4] = Figure{ FIGURE_RECTENGLE,Float2{ pos.x,pos.y + half_h }, Float2{ size.x ,bor_thick },{ 80,0,120,255 },0 };
}
// [=]<------------------------------------------------------------->[=]

Float2& Window::S_Pos()       { changed_XY_WH = true; return pos; }
Float2& Window::S_Size()      { changed_XY_WH = true; return size; }
float&  Window::S_Bor_Thick() { changed_XY_WH = true; return bor_thick; }
// [=]<------------------------------------------------------------->[=]
    
const Float2& Window::G_Pos()       { return pos; }
const Float2& Window::G_Size()      { return size; }
const float& Window::G_Bor_Thick() { return bor_thick; }

// [=]<------------------------------------------------------------->[=]
void Window::Recalculate() {
    if (changed_XY_WH || changed_Thick) {
        float half_w{ (size.x - bor_thick) * 0.5f };
        float half_h{ (size.y - bor_thick) * 0.5f };
        // Background
        if (changed_XY_WH) {
            figs[0].S_Pos() = Float2{ pos.x,pos.y }; figs[0].S_Size() = Float2{ size.x ,size.y };
        }
        figs[1].S_Pos() = { pos.x - half_w, pos.y }; figs[1].S_Size() = { bor_thick, size.y };
        figs[2].S_Pos() = { pos.x + half_w, pos.y }; figs[2].S_Size() = { bor_thick, size.y };
        figs[3].S_Pos() = { pos.x,pos.y - half_h };  figs[3].S_Size() = { size.x ,bor_thick };
        figs[4].S_Pos() = { pos.x,pos.y + half_h };  figs[4].S_Size() = { size.x ,bor_thick };
    }
    changed_XY_WH = false;
    changed_Thick = false;
}
void Window::G_Figures(vector<Figure*>& gFigures) {
    for (int i{ 0 };i < figs.size();i++) {
        gFigures.push_back(&figs[i]);
    }
}

// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Program Window }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

void wuProg_Window::ON(string gTitle,Float2 gPos,Float2 gSize) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("don't work", 100, 100, SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        SDL_Log("System constr window failed");
    }

    S_Title(gTitle);
    S_Pos(gPos);
    S_Size(gSize);
}
void wuProg_Window::OFF() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
// [=]<------------------------------------------------------------->[=]

void wuProg_Window::S_Title(string gTitle) {
    title = gTitle;
    SDL_SetWindowTitle(window, gTitle.c_str());
}
void wuProg_Window::S_Pos(Float2 gPos){
    pos = gPos;
    SDL_SetWindowPosition(window, gPos.x, gPos.y);
}
void wuProg_Window::S_Size(Float2 gSize) {
    size = gSize;
    SDL_SetWindowSize(window, gSize.x, gSize.y);
}
// [=]<------------------------------------------------------------->[=]

SDL_Window* wuProg_Window::G_Window() { return window; }
const string* wuProg_Window::G_Title() { return &title; }
const Float2* wuProg_Window::G_Pos() { return &pos; }
const Float2* wuProg_Window::G_Size() { return &size; }

// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ 2D_Buffer }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

void wu2D_Buffer::CollectGeometry() {
    figures.clear();
    vertexes.clear();
    indices.clear();
    last_indice = 0;

    for (int i{0};i < windows.size();i++) {
        windows[i].Recalculate();
        windows[i].G_Figures(figures);
    }

    for (int i{0};i < figures.size();i++) {
        figures[i]->Recalculate();
        figures[i]->G_Geometry(vertexes, indices, last_indice);
    }
}