#include "wuObjects_Buffer.h"

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Figure }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ Constructor }<-============================]
Figure::Figure() {
    
}
Figure::Figure(Figure_Type gType, Pixel gColor, Int2 gPos, Int2 gSize, int gAngle) {
    type = gType;color = gColor;pos = gPos;size = gSize, angle = gAngle;
}
// [============================->{ Set }<-============================]
void Figure::S_Type(Figure_Type gType) {
    type = gType;
}
void Figure::S_Color(Pixel gColor) {
    color = gColor;
}
void Figure::S_Pos(Int2 gPos) {
    pos = gPos;
}
void Figure::S_Size(Int2 gSize) {
    size = gSize;
}
void Figure::S_Angle(int gAngle) {
    angle = gAngle;
}
// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Object_Buffer }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ Constructor }<-============================]
wuObject_Buffer::wuObject_Buffer(Figure* gFigures, int gFigure_count) {
    figures = gFigures;
    figure_count = gFigure_count;
}