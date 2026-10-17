#ifndef WarpUrdan_H
#define WarpUrdan_H

#include "wuRender.h"
#include "wuCycle.h"
#include "wu2D_Graphics.h"

class WU {
public:
    wuProg_Window window;
    wuCycle cycle;
    wuRender render;
    wu2D_Buffer buff;
    wuStyle style;
};

#endif // WarpUrdan_H

// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ ... }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]
// [=]<------------------------------------------------------------->[=]

/*
Mouse event_
When presed RMB create rect, press again on rect to close it.
Rect must create blanck that return hovered and pressed to the figure.]

in separated file
enum Press_Secrtor_TYPE{
SECTOR_BUTTON //add other type
SECTOR_WINDOW //add other type
SECTOR_PROGRAM_WINDOW
};
class Press_sector { // for everything, prgwin,win,elem
private:
vector<Point> points
public:
bool MousInside();
void S_Points();
};

class PopOut {
private:
wuStyle* style{nullptr};
vector<Element>
vector<Figure> figs[5];

UInt2 pos{0,0};
UInt2 size{0,0};
uint32_t bor_thick{0};

bool created : 1;
bool changed : 1;
public:

};
*/