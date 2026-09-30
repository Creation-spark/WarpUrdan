#include "wuCycle.h"

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Frame }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]

wuFrame::wuFrame() {
    Start();
}

// [=]<------------------------------------------------------------->[=]

void wuFrame::Set_FPSLimit(int fps) {
    perFrame = 1000 / fps;
}

// [=]<------------------------------------------------------------->[=]

void wuFrame::Start() {
    start = SDL_GetTicks();
}
void wuFrame::End() {
    end = SDL_GetTicks();
    cicle = end - start;
    if (cicle < perFrame) {
        SDL_Delay(perFrame - cicle);
    }
    SDL_Log("%i ms\n",cicle);
}
// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Event }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]

wuEvent::wuEvent() :
    event(new SDL_Event) {
}
wuEvent::~wuEvent() {
    delete event;
}
// [=]<------------------------------------------------------------->[=]

bool wuEvent::NewEvent() {
    return SDL_PollEvent(event);
}
wuResult wuEvent::Mous() {
    //switch (){}

    return WUR_NONE;
}
wuResult wuEvent::Keyboard() {
    switch (event->key.key) {
    case SDLK_ESCAPE:
        return WUR_QUIT;
        break;
    }

    return WUR_NONE;
}
wuResult wuEvent::Program() {
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return WUR_QUIT;
        break;
    }

    return WUR_NONE;
}
// [=]<------------------------------------------------------------->[=]

bool wuEvent::Events() {
    while (NewEvent()) {
        if ((result = Mous()) != WUR_NONE) { break; }
        else if ((result = Keyboard()) != WUR_NONE) { break; }
        else if ((result = Program()) != WUR_NONE) { break; }
    }
    if (result == WUR_QUIT) {
        return false;
    }
    else { return true; }
}
// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ Cycle }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]

bool wuCycle::Runing() {
    frame.End();
    frame.Start();
    return event.Events();
    
}

// [=]<------------------------------------------------------------->[=]

void wuCycle::FPSUpLimit(int fps) {
    if (fps > 1) {
        frame.Set_FPSLimit(fps);
    }
    }