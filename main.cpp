// Just ADAPT to convert absurdity at power.

#define SDL_MAIN_HANDLED
#include "WU_Moduls.h"

int main() {
    WU_ModulsCreate();
    WU_ModulsPrepare();

    m_Objects->Cr_FigureArray(8);
    
    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 100,100 }, { 100,100 }, 0
    );
    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 600,100 }, { 100,100 }, 0
    );
    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 600,600 }, { 100,100 }, 0
    );
    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 100,600 }, { 100,100 }, 0
    );

    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 350,100 }, { 100,100 }, 0
    );
    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 600,350 }, { 100,100 }, 0
    );
    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 350,600 }, { 100,100 }, 0
    );
    m_Objects->Add_Figure(
        FIGURE_RECT, { 255,160,0,255 },
        { 100,350 }, { 100,100 }, 0
    );
    int anim_frame{ 0 };
    Figure* figs = m_Objects->G_FigureArray();
    int step{ 50 };

    for (;;) {
        WU_CicleStart({0,0,0,255});

        if (anim_frame % 5 == 0) {
            for (int i{ 0 };i < 8;i++) {
                Figure* fig = &figs[i];
                if (fig->pos.y == 100 && fig->pos.x < 600) {
                    fig->pos.x += step;
                }
                else if (fig->pos.x == 600 && fig->pos.y < 600) {
                    fig->pos.y += step;
                }
                else if (fig->pos.y == 600 && fig->pos.x > 100) {
                    fig->pos.x -= step;
                }
                else if (fig->pos.x == 100 && fig->pos.y > 100) {
                    fig->pos.y -= step;
                }
            }
        }

        anim_frame++;
        if (anim_frame == 25) {
            anim_frame = 0;
        }
        WU_CicleEnd();
    }

    WU_ModulsDelete();
}