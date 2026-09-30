#ifndef WUSPACE_H
#define WUSPACE_H
#include "SDL3/SDL.h"
#include <string>
#include "wuType.h"

// [=]<------------------------------------------------------------->[=]

enum Figure_TYPE {
    FIGURE_EMPTY,
    FIGURE_TRINGLE,
    FIGURE_RECTENGLE,
    FIGURE_CIRCL,
    FIGURE_POLYGONE
};
struct Figure {
    Figure_TYPE type{ FIGURE_EMPTY };
    Int2 pos{ 10,10 };
    UInt2 size{ 10,10 };
    Pixel color{ 255,255,255,255 };
    int turn{ 0 };

    // Constructor
    Figure();
    Figure(Figure_TYPE Type, Int2 Pos, UInt2 Size, Pixel Color, int Turn);
};

// [=]<------------------------------------------------------------->[=]

struct Draw_Buffer {
    // Over UI
    Vec<Figure> OverUI{ 1 };
    Vec<Figure> UI{ 1 };
    Vec<Figure> UnderUI{ 1 };

    // Return layer
    Vec<Figure>& G_Layer(int layer);
};

// [=]<------------------------------------------------------------->[=]

// Tips "SDL_UpdateTexture, sdltexstrim"
class Render {
private:
    SDL_Renderer* renderer{ nullptr };
    Draw_Buffer* buff{ nullptr };
public:
    Render();
    Render(SDL_Window* window, Draw_Buffer* gBuff);
    ~Render();

    void Clear_Render();
    void Present_Render();
    
    void Render_Figures();
};

// [=]<------------------------------------------------------------->[=]

class wuSpace {
    SDL_Window* window{ nullptr };

    Draw_Buffer* buff{ nullptr };
    Render render;
public:
    wuSpace();
    ~wuSpace();

    // exist 3 layers, delete all data
    void Set_LayerSize(int layer, int size);
    Figure* Get_Figure(int layer, int id);

    void Render_Draw_Buffer();

    void ProgWin_Title(std::string Title);
    void ProgWin_Pos(int X, int Y);
    void ProgWin_Size(int Withd, int Hight);
};

#endif // WUSPACE_H

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ ... }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]