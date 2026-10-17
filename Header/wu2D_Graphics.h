#ifndef WU_2D_GRAPHIC_H
#define WU_2D_GRAPHIC_H
#include "SDL3/SDL.h"
#include "wuType.h"
#include "wuStyle.h"
#include <string>
using std::string;
#include <vector>
using std::vector;
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Figure }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

enum Figure_TYPE {
    FIGURE_NONE,
    FIGURE_TRIANGEL,
    FIGURE_RECTENGLE
};
struct Figure {
private:
    vector<SDL_Vertex> vertexes;
    vector<int>        indices;

    Figure_TYPE type{ FIGURE_NONE };
    Float2      pos{ 0,0 };
    Float2      size{ 0,0 };
    Pixel       color{ 255, 0, 0, 255 };
    int         turn{ 0 };

    uint8_t changed_Type  : 1;
    uint8_t changed_XY_WH : 1;
    uint8_t changed_Color : 1;
public:
    Figure();
    Figure(Figure_TYPE gType, Float2 gPos, Float2 gSize, Pixel gColor, int gTurn);

    Figure_TYPE& S_Type();
    Float2&      S_Pos();
    Float2&      S_Size();
    Pixel&       S_Color();
    int&         S_Turn();

    const Figure_TYPE& G_Type();
    const Float2&      G_Pos();
    const Float2&      G_Size();
    const Pixel&       G_Color();
    const int&         G_Turn();

    void Recalculate();
    void G_Geometry(vector<SDL_Vertex>& gVertexes, vector<int>& gIndices, int& gLast_indice);
};
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Element }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]
enum Element_TYPE {
    ELEMENT_EMPTY,
    ELEMENT_BUTTON,
    ELEMENT_SWITCH,
    ELEMENT_SWITCH_BUTTON,
    ELEMENT_VERTICAL_SLIDER,
    ELEMENT_HORISONTAL_SLIDER,
    ELEMENT_LIST,
    ELEMENT_TEXT_BOX
};
class Element{
private:
wuStyle*       style{nullptr};
vector<Figure> figs[2];
uint8_t        variant{0}; // change form of the same type element

Element_TYPE type{ELEMENT_EMPTY};
Float2       pos{0,0};
Float2       size{0,0};

public:
};
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Window }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

class Window {
private:
    wuStyle*        style{ nullptr };
    vector<Element> elements;
    vector<Figure>  figs;

    Float2 pos{ 0,0 };
    Float2 size{ 0,0 };
    float  bor_thick{ 0 };

    bool created : 1;
    bool changed_XY_WH : 1;
    bool changed_Thick : 1;
public:
    Window();
    Window(Float2 gPos, Float2 gSize, float gBor_thick);

    void Create_Frame();

    Float2& S_Pos();
    Float2& S_Size();
    float&  S_Bor_Thick();

    const Float2& G_Pos();
    const Float2& G_Size();
    const float&  G_Bor_Thick();

    void Recalculate();
    void G_Figures(vector<Figure*> &gFigures);
};
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Program Window }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

// Style need be done
class wuProg_Window {
private:
    SDL_Window* window{nullptr};

    string title{ "None" };
    Float2 pos{ 0,0 };
    Float2 size{ 0,0 };
public:
    // ON as First
    void ON(string gTitle,Float2 gPos,Float2 gSize);
    // OFF as Last
    void OFF();

    void S_Title(string gTitle);
    void S_Pos(Float2 gPos);
    void S_Size(Float2 gSize);

    SDL_Window* G_Window();
    const string* G_Title();
    const Float2* G_Pos();
    const Float2* G_Size();
};
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ 2D_Buffer }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

struct wu2D_Buffer {
    vector<Window> windows;
    vector<Figure*> figures;
    vector<SDL_Vertex> vertexes;
    vector<int> indices;
    int last_indice{ 0 };

    void CollectGeometry();
};

#endif // WU_2D_GRAPHIC_H
// [=]<-------------------------------------------------------------->[=]