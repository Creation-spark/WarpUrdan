// [============================->{ Includes }<-============================]
#include "wuCycle.h"
// [============================->{ Event }<-============================]
bool wuEvent::Get_NewEvent() {
    return SDL_PollEvent(&event);
}
wuResult wuEvent::Mous_Events() {
    return WUR_NONE;
}
wuResult wuEvent::Keyboard_Events() {
    switch (event.key.key)
    {
    case SDLK_ESCAPE:
        return WUR_QUIT;
        break;
    }
    return WUR_NONE;
}
wuResult wuEvent::Program_Events() {
    switch (event.type)
    {
    case SDL_EVENT_QUIT:
        return WUR_QUIT;
        break;
    }
    return WUR_NONE;
}
bool wuEvent::Process_Events() {
    while (Get_NewEvent()) {
        if (Mous_Events() == WUR_QUIT) return false;
        else if (Keyboard_Events() == WUR_QUIT) return false;
        else if (Program_Events() == WUR_QUIT) return false;
    }
    return true;
}
// [============================->{ Frame }<-============================]
wuFrame::wuFrame() {
    Set_FPSLimit(25);
}
void wuFrame::Set_FPSLimit(int gLimit) {
    expected = 1000 / gLimit;
}
void wuFrame::Set_StartTime() {
    start = SDL_GetTicks();
}
void wuFrame::Set_EndTime() {
    end = SDL_GetTicks();
}
void wuFrame::Generate_Deley() {
    cicle = end - start;
    if (cicle < expected) {
        SDL_Delay(expected - cicle);
    }
    SDL_Log("%ims");
}
// [============================->{ Cycle }<-============================]
bool wuCycle::Is_Runing() {
    frame.Set_EndTime();
    frame.Generate_Deley();
    frame.Set_StartTime();

    return event.Process_Events();
}