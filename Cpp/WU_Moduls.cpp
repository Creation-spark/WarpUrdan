#include "WU_Moduls.h"

wuSystem* m_System{nullptr};
wuCicle* m_Cicle{nullptr};
wuObjects* m_Objects{nullptr};

// [============================->{ Moduls }<-============================]
void WU_ModulsCreate() {
    cout << "Create" << endl;
    m_System = new wuSystem;
    m_Cicle = new wuCicle;
    m_Objects = new wuObjects;
}
void WU_ModulsDelete() {
    cout << "Delete" << endl;
    delete m_Objects;
    delete m_Cicle;
    delete m_System;

    SDL_Quit();
    exit(0);
}
void WU_ModulsPrepare() {
    cout << "Prepare" << endl;
    m_System->In_Video();
    m_System->Cr_Window("None",{800,800},SDL_WINDOW_RESIZABLE);
    m_System->Cr_Renderer();

    m_Objects->prgrm_win.S_Window(m_System->G_Window());
    m_Cicle->frame.S_Rate(25);
    m_Cicle->render.S_Renderer(m_System->G_Renderer());
}
// [============================->{ Cicle }<-============================]
void WU_CicleStart(Pixel color) {
    m_Cicle->frame.S_Start();
        if (m_Cicle->event.Pr_Events()) {
            WU_ModulsDelete();
        }
        m_Cicle->render.R_ClearSurface({0, 0, 0, 255});
}
void WU_CicleEnd() {
    m_Cicle->render.S_Objects_Buffer(m_Objects->G_ObjectBuffer());
    m_Cicle->render.R_Objects();
    m_Cicle->render.R_Present();
    m_Cicle->frame.S_End();
    m_Cicle->frame.S_Deley();
}