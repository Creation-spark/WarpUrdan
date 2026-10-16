// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Includes }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]
#include "wu2D_Geometry.h"
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Figure }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

Figure::Figure() {
    
}
Figure::Figure(Figure_TYPE gType, Int2 gPos, Int2 gSize, Pixel gColor, int gTurn) {
    S_Type(gType);
    S_Pos(gPos);
    S_Size(gSize);
    S_Color(gColor);
    S_Turn(gTurn);

    changed_geometry = true;
    changed_color = true;
}
// [=]<-------------------------------------------------------------->[=]

void Figure::S_Type(Figure_TYPE gType) {
    type = gType;
    switch (type) {
    case FIGURE_TRIANGEL: {
        vertexes.resize(3);
        indices.resize(3);

        vertexes = { { 0,-0.5 },{ 0.5,0.5 },{ -0.5,0.5 } };
        indices = { 0,2,1 };
        break;
    }
    case FIGURE_RECTENGLE: {
        vertexes.resize(4);
        indices.resize(6);

        vertexes = { { -0.5,-0.5 },{ 0.5,-0.5 },{ 0.5,0.5 },{ -0.5,0.5 } };
        indices = { 0,3,1, 1,3,2 };
        break;
    }
    default:

        break;
    }

    changed_geometry = true;
}
void Figure::S_Pos(Int2 gPos) { pos = gPos; changed_geometry = true; }
void Figure::S_X(int gX) { pos.x = gX; changed_geometry = true; }
void Figure::S_Y(int gY) { pos.y = gY; changed_geometry = true; }
void Figure::S_Size(Int2 gSize) { size = gSize; changed_geometry = true; }
void Figure::S_Width(int gWidth) { size.x = gWidth; changed_geometry = true; }
void Figure::S_Height(int gHeight) { size.y = gHeight; changed_geometry = true; }
void Figure::S_Color(Pixel gColor) { color = gColor; changed_color = true; }
void Figure::S_R(uint8_t gR) { color.r = gR; changed_color = true; }
void Figure::S_G(uint8_t gG) { color.g = gG; changed_color = true; }
void Figure::S_B(uint8_t gB) { color.b = gB; changed_color = true; }
void Figure::S_A(uint8_t gA) { color.a = gA; changed_color = true; }
void Figure::S_Turn(int gTurn) { turn = gTurn; changed_geometry = true; }
// [=]<-------------------------------------------------------------->[=]

const Figure_TYPE* Figure::G_Type() { return &type; }
const Int2* Figure::G_Pos() { return &pos; }
const Int2* Figure::G_Size(){ return &size; }
const Pixel* Figure::G_Color(){ return &color; }
const int* Figure::G_Turn() { return &turn; }
// [=]<-------------------------------------------------------------->[=]

void Figure::Recalculate() {
    switch (type) {
    case FIGURE_TRIANGEL: {
        if (changed_geometry) {
            float W = 0.5 * size.x;
            float H = 0.5 * size.y;
            vertexes[0] = { 0,-H + pos.y };
            vertexes[1] = { W + pos.x, H + pos.y };
            vertexes[2] = { -W + pos.x, H + pos.y };
        }
        if (changed_color) {
            float sub = 1.0f / 255.0f;
            SDL_FColor col{ color.r * sub,color.g * sub,color.b * sub,color.a * sub, };
            for (int i{ 0 };i < 3;i++) {
                vertexes[i].color = col;
            }
        }
        break;
    }
    case FIGURE_RECTENGLE: {
        if (changed_geometry) {
            float W = 0.5 * size.x;
            float H = 0.5 * size.y;
            vertexes[0] = { -W + pos.x,-H + pos.y };
            vertexes[1] = { W + pos.x, -H + pos.y };
            vertexes[2] = { W + pos.x, H + pos.y };
            vertexes[3] = { -W + pos.x, H + pos.y };
        }
        if (changed_color) {
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

    changed_geometry = false;
    changed_color = false;
}
void Figure::G_Geometry(vector<SDL_Vertex>& gVertexes, vector<int>& gIndices) {
    Recalculate();

    for (int i{ 0 };i < vertexes.size();i++) {
        gVertexes.push_back(vertexes[i]);
    }
    int arr_Size{ (int)gIndices.size() };
    for (int i{ 0 };i < indices.size();i++) {
        gIndices.push_back(indices[i] + arr_Size);
    }
}
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ 2D_Buffer }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

void wu2D_Buffer::CollectGeometry() {
    vertexes.clear();
    indices.clear();

    for (int i{ 0 };i < figures.size();i++) {
        figures[i]->Recalculate();
    }
    for (int i{ 0 };i < figures.size();i++) {
        figures[i]->G_Geometry(vertexes,indices);
    }
}