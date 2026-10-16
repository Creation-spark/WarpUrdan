#ifndef WUWINDOW_H
#define WUWINDOW_H
#include "SDL3/SDL.h"
#include "wuType.h"
#include <string>
using std::string;

class wuWindow {
private:
    SDL_Window* window{nullptr};

    string title{ "None" };
    UInt2 pos{ 0,0 };
    UInt2 size{ 0,0 };
public:
    // ON as First
    void ON(string gTitle,UInt2 gPos,UInt2 gSize);
    // OFF as Last
    void OFF();

    void S_Title(string gTitle);
    void S_Pos(UInt2 gPos);
    void S_Size(UInt2 gSize);

    SDL_Window* G_Window();
    const string* G_Title();
    const UInt2* G_Pos();
    const UInt2* G_Size();
};

#endif // WUWINDOW_H
// [=]<------------------------------------------------------------->[=]