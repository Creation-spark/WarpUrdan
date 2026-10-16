// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Includes }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]
#include "wuWindow.h"
// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ Program Window }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]

void wuWindow::ON(string gTitle,UInt2 gPos,UInt2 gSize) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("don't work", 100, 100, SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        SDL_Log("System constr window failed");
    }

    S_Title(gTitle);
    S_Pos(gPos);
    S_Size(gSize);
}
void wuWindow::OFF() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
// [=]<------------------------------------------------------------->[=]

void wuWindow::S_Title(string gTitle) {
    title = gTitle;
    SDL_SetWindowTitle(window, gTitle.c_str());
}
void wuWindow::S_Pos(UInt2 gPos){
    pos = gPos;
    SDL_SetWindowPosition(window, gPos.x, gPos.y);
}
void wuWindow::S_Size(UInt2 gSize) {
    size = gSize;
    SDL_SetWindowSize(window, gSize.x, gSize.y);
}
// [=]<------------------------------------------------------------->[=]

SDL_Window* wuWindow::G_Window() { return window; }
const string* wuWindow::G_Title() { return &title; }
const UInt2* wuWindow::G_Pos() { return &pos; }
const UInt2* wuWindow::G_Size() { return &size; }