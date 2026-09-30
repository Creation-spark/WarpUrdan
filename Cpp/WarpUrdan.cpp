#include "WarpUrdan.h"

namespace wu {
    wuCycle* cycle = nullptr;
    wuSpace* space = nullptr;

    void WU_SDL_InitVideo() {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("Video failed");
            exit(0);
        }
    }
    // [=]<------------------------------------------------------------->[=]
    void WU_CreateModuls() {
        WU_SDL_InitVideo();

        cycle = new wuCycle;
        space = new wuSpace;
    }
    void WU_DeleteModuls() {
        delete space;
        delete cycle;
    }
}