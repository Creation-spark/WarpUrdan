/*
Only fire can cause a firestorm.
But you are a spark.
You are the smallest one.
So make them fear you.
*/

#define SDL_MAIN_HANDLED
#include "WarpUrdan.h"
using namespace wu;

int main() {
    WU_CreateModuls();

    space->Set_LayerSize(0, 6);
    
    Figure* fig{ nullptr };
    fig = space->Get_Figure(0, 0);
    fig->type = FIGURE_RECTENGLE;
    fig->pos = { 10,10 };

    fig = space->Get_Figure(0, 1);
    fig->type = FIGURE_RECTENGLE;
    fig->pos = { 10,20 };

    fig = space->Get_Figure(0, 2);
    fig->type = FIGURE_RECTENGLE;
    fig->pos = { 20,10 };

    // [=]<------------------------------------------------------------->[=]
    
    fig = space->Get_Figure(0, 3);
    fig->type = FIGURE_RECTENGLE;
    fig->pos = { 90,90 };

    fig = space->Get_Figure(0, 4);
    fig->type = FIGURE_RECTENGLE;
    fig->pos = { 80,90 };

    fig = space->Get_Figure(0, 5);
    fig->type = FIGURE_RECTENGLE;
    fig->pos = { 90,80 };

    while (cycle->Runing()) {
        
        space->Render_Draw_Buffer();

    }
    WU_DeleteModuls();
    return 0;
}