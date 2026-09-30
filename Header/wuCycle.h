#ifndef WUCYCLE_H
#define WUCYCLE_H
#include "SDL3/SDL.h"
#include "wuType.h"

class wuFrame {
private:
    Uint64 start{ 0 };
    Uint64 end{ 0 };
    Uint64 cicle{ 0 };
    Uint64 perFrame{ 40 };
public:
    wuFrame();

    void Set_FPSLimit(int fps);

    void Start();
    void End();
};

class wuEvent {
private:
    SDL_Event* event{nullptr};
    wuResult result{ WUR_NONE };
public:
    wuEvent();
    ~wuEvent();

    bool NewEvent();
    wuResult Mous();
    wuResult Keyboard();
    wuResult Program();
    bool Events();

    void S_Event(SDL_Event* Event) { event = Event; }
};

class wuCycle {
private:
    wuFrame frame;
    wuEvent event;
public:
    bool Runing();

    void FPSUpLimit(int fps);
};

#endif // WUCYCLE_H

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ ... }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]