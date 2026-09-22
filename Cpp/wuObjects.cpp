#include "wuObjects.h"

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Program_Window }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ Set }<-============================]
void Program_Window::S_Window(SDL_Window* gWindow) {
    window = gWindow;
}
void Program_Window::S_Title(string gTitle) {
    title = gTitle;
    SDL_SetWindowTitle(window, title.c_str());
}
void Program_Window::S_Pos(Int2 gPos) {
    pos = gPos;
    SDL_SetWindowPosition(window, pos.x, pos.y);
}
void Program_Window::S_Size(Int2 gSize) {
    size = gSize;
    SDL_SetWindowSize(window, size.x, size.y);
}

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Objects }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]
// [============================->{ Destructor }<-============================]
wuObjects::~wuObjects() {
    delete figures;
}
// [============================->{ Create }<-============================]
void wuObjects::Cr_FigureArray(int amount) {
    figures = new Figure[amount];
}
// [============================->{ Get }<-============================]
Figure* wuObjects::G_FigureArray() {
    return figures;
}
wuObject_Buffer* wuObjects::G_ObjectBuffer() {
    return new wuObject_Buffer{ figures,figure_count };
}
// [============================->{ Add }<-============================]
void wuObjects::Add_Figure(Figure_Type gType, Pixel gColor, Int2 gPos, Int2 gSize, int gAngle) {
    figures[figure_count] = Figure(gType, gColor, gPos, gSize, gAngle);
    figure_count += 1;
}