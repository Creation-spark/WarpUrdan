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
    wu.window.ON("Fine", { 0,0 }, { 200,200 });
    wu.render.ON(wu.window.G_Window());

    wu.buff.figures.push_back(new Figure{ FIGURE_RECTENGLE,{ 5,5 },{ 10,10 },{ 130,0,255,255 },0 });

    while (wu.cycle.Is_Runing()) {
        wu.render.Clear();

        // ...

        wu.render.Present(wu.buff);
    }

    delete wu.buff.figures[0];
    wu.render.OFF();
    wu.window.OFF();
    return 0;
}