#ifndef WU_MODULS_H
#define WU_MODULS_H

#include "wuSystem.h"
#include "wuCicle.h"
#include "wuObjects.h"

extern wuSystem* m_System;
extern wuCicle* m_Cicle;
extern wuObjects* m_Objects;

// System
void WU_ModulsCreate();
void WU_ModulsDelete();
void WU_ModulsPrepare();
// Cicle
void WU_CicleStart(Pixel color);
void WU_CicleEnd();

#endif // WU_MODULS_H

// [============================->{ ... }<-============================]