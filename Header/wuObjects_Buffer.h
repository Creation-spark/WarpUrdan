#ifndef WUOBJ_STRUCT_H
#define WUOBJ_STRUCT_H

#include "wuType.h"

enum Figure_Type {
    FIGURE_RECT
};
struct Figure {
    // Data
    Figure_Type type{ FIGURE_RECT };
    Pixel color{ 0,0,0,255 };
    Int2 pos{ 0,0 };
    Int2 size{ 100,100 };
    int angle{ 0 };

    // Constructor
    Figure();
    Figure(Figure_Type gType, Pixel gColor, Int2 gPos, Int2 gSize, int gAngle);
    // Set
    void S_Type(Figure_Type gType);
    void S_Color(Pixel gColor);
    void S_Pos(Int2 gPos);
    void S_Size(Int2 gSize);
    void S_Angle(int gAngle);
};

struct wuObject_Buffer {
    //Figure
    Figure* figures{ nullptr };
    int figure_count{ 0 };

    wuObject_Buffer(Figure* gFigures, int gFigure_count);
};


#endif // WUOBJ_STRUCT_H

// [============================->{ ... }<-============================]