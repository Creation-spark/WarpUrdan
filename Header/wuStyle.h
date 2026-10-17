#ifndef WU_STYLE_H
#define WU_STYLE_H
#include "wuType.h"
#include <vector>
using std::vector;

struct wuStyle {
    Pixel program_window_bg{ 20,0,40,255 };

    Pixel window_background{ 60,0,120,255 };
    Pixel window_border{ 80,0,120,255 };

    vector<Pixel> button_standart[3];
    vector<Pixel> button_hovered[3];
    vector<Pixel> button_pressed[3];
};

#endif // WU_STYLE_H