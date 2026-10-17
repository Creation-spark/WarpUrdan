/*
Only fire can cause a firestorm.
But you are a spark.
You are the smallest one.
So make them fear you.
*/
// [=]<-------------------------------------------------------------->[=]
#define SDL_MAIN_HANDLED
#include "WarpUrdan.h"
// [=]<-------------------------------------------------------------->[=]
int main() {
    WU wu;
    wu.window.ON("Fine", { 1920*0.5f,1080*0.5f }, { 400,200 });
    wu.render.ON(wu.window.G_Window());

    wu.buff.windows.push_back(Window{ { 150,50 },{ 200,100 },4 });

    while (wu.cycle.Is_Runing()) {
        wu.render.Clear();

        // ...

        wu.render.Present(wu.buff);
    }

    wu.render.OFF();
    wu.window.OFF();
    return 0;
}