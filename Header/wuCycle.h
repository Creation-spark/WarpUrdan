#ifndef WUCYCLE_H
#define WUCYCLE_H
#include "SDL3/SDL.h"
#include "wuType.h"

class wuEvent {
private:
    SDL_Event event;
    wuResult result;
public:
    bool Get_NewEvent();
    wuResult Mous_Events();
    wuResult Keyboard_Events();
    wuResult Program_Events();
    bool Process_Events();
};
// [=]<------------------------------------------------------------->[=]
class wuFrame {
private:
    int start{ 0 };
    int end{ 0 };
    int cicle{ 0 };
    int expected{ 0 };
public:
    wuFrame();

    void Set_FPSLimit(int n_limit);
    void Set_StartTime();
    void Set_EndTime();
    void Generate_Deley();
};
// [=]<------------------------------------------------------------->[=]
class wuCycle {
public:
    wuEvent event;
    wuFrame frame;

    // Cycle condition
    bool Is_Runing();
};

#endif // WUCYCLE_H
// [=]<------------------------------------------------------------->[=]