#ifndef WUGRAPHIC_H
#define WUGRAPHIC_H
#include "SDL3/SDL.h"
#include "wuType.h"
#include <vector>
using std::vector;

// [=]<-------------------------------------------------------------->[=]

enum Figure_TYPE {
    FIGURE_NONE,
    FIGURE_TRIANGEL,
    FIGURE_RECTENGLE
};
struct Figure {
private:
    vector<SDL_Vertex> vertexes;
    vector<int> indices;

    Figure_TYPE type{ FIGURE_NONE };
    Int2 pos{ 0,0 };
    Int2 size{ 0,0 };
    Pixel color{255, 0, 0, 255};
    int turn{ 0 };

    uint8_t changed_geometry : 1;
    uint8_t changed_color : 1;
public:
    Figure();
    Figure(Figure_TYPE gType, Int2 gPos, Int2 gSize, Pixel gColor, int gTurn);

    void S_Type(Figure_TYPE gType);
    void S_Pos(Int2 gPos);
    void S_X(int gX);
    void S_Y(int gY);
    void S_Size(Int2 gSize);
    void S_Width(int gWidth);
    void S_Height(int gHeight);
    void S_Color(Pixel gColor);
    void S_R(uint8_t gX);
    void S_G(uint8_t gY);
    void S_B(uint8_t gX);
    void S_A(uint8_t gY);
    void S_Turn(int gTurn);

    const Figure_TYPE* G_Type();
    const Int2* G_Pos();
    const Int2* G_Size();
    const Pixel* G_Color();
    const int* G_Turn();

    void Recalculate();
    void G_Geometry(vector<SDL_Vertex>& gVertexes, vector<int>& gIndices);
};
// [=]<-------------------------------------------------------------->[=]

struct Window {
private:
    
public:
    
};
// [=]<-------------------------------------------------------------->[=]

struct wu2D_Buffer {
    vector<Window> windows;
    vector<Figure*> figures;
    vector<SDL_Vertex> vertexes;
    vector<int> indices;

    void CollectGeometry();
};

#endif // WUGEOMETRY_H
// [=]<-------------------------------------------------------------->[=]

/*
Deside what to save at vectors: & or *

Create class Window that can contain element.
class Element can be: button, slider, text box, switch,
Make everything divided by grid
*/