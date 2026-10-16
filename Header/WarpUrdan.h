#ifndef WarpUrdan_H
#define WarpUrdan_H

#include "wuWindow.h"
#include "wuRender.h"
#include "wuCycle.h"
#include "wu2D_Geometry.h"

class WU {
public:
    wuWindow window;
    wuCycle cycle;
    wuRender render;
    wu2D_Buffer buff;
};

#endif // WarpUrdan_H

// [=#=#=#=#=#=#=#=#=#=#=#=#=#=#->{ ... }<-=#=#=#=#=#=#=#=#=#=#=#=#=#=#]
// [=]<------------------------------------------------------------->[=]

/*
Mouse event_
When presed RMB create rect, press again on rect to close it.
Rect must create blanck that return hovered and pressed to the figure.
*/

/*
use vec.insert() to store vertexes in buff

in separated file
enum Press_Secrtor_TYPE{
SECTOR_BUTTON //add other type
SECTOR_WINDOW //add other type
SECTOR_PROGRAM_WINDOW
};
class Press_sector {
private:
vector<Point> points
public:
bool MousInside();
void S_Points();
};
*/

/* in separated file
struct wuStyle {
Pixel program_window_bg{20,0,40,255};
Pixel window_background{60,0,120,255};
Pixel window_border{80,0,120,255};
array<Pixel> button_standart[3];
array<Pixel> button_hovered[3];
array<Pixel> button_pressed[3];
};


// Change file name to wuWindows
// S_ return *
// G_ return const *

enum Element_TYPE {
ELEMENT_EMPTY,
ELEMENT_BUTTON,
ELEMENT_SWITCH,
ELEMENT_SWITCH_BUTTON,
ELEMENT_VERTICAL_SLIDER,
ELEMENT_HORISONTAL_SLIDER,
ELEMENT_LIST,
ELEMENT_TEXT_BOX
}
class Element{
private:
wuStyle* style{nullptr};
vector<Figure> figs[2];
uint8_t variant{0}; // change form of the same type element

Element_TYPE type{ELEMENT_EMPTY};
UInt2 pos{0,0};
UInt2 size{0,0};

public:
};

class Grid {

}

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

class Window {
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
Window(UInt2 gPos, UInt2 gSize, uint32_t gBor_thick, Pixel gBg_color, Pixel gBor_color) {
pos = gPos;
size = gSize;
bor_thick = gBor_thick;
bg_color = gBg_color;
bor_color = gBor_color;

float half_w{(size.x-bor_thick)*0.5};
float half_h{(size.y-bor_thick)*0.5};
// Background
figs.push_back(FIGURE_RECTENGLE, {pos.x,pos.y},{size.x ,size.y},bg_color,0);
// Border
figs.push_back(FIGURE_RECTENGLE, {pos.x - half_w, pos.y},{bor_thick, size.y},bor_color,0);
figs.push_back(FIGURE_RECTENGLE, {pos.x + half_w, pos.y},{bor_thick , size.y},bor_color,0);
figs.push_back(FIGURE_RECTENGLE, {pos.x,pos.y-half_h},{size.x ,bor_thick},bor_color,0);
figs.push_back(FIGURE_RECTENGLE, {pos.x,pos.y+half_h},{size.x ,bor_thick},bor_color,0);

created = true;
changed = true;
}

// need function to create bg and border separatly to use it for recalculation of whole window.
void Recalculate() {

}

// Changed check neeeeeeed
void S_Position(UInt2 gPos) {pos = gPos;}
void S_Size(UInt2 gSize) {size = gSize;}
void S_Border_Thicknes(UInt2 gBor_thick) {bor_thick = gBor_thick;}
void S_Background_Color(UInt2 gBg_color) {bg_color = gBg_color;}
void S_Border_Color(UInt2 gBor_color) {bor_color = gBor_color;}

// G_ сам сделаешь
};
*/