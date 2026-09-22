#pragma once
#ifndef WUTYPE_H
#define WUTYPE_H
#include <cstdint>
#include <string>

enum wuResult {
    WU_SUCCESS,
    WU_FUCK,
    WU_NONE
};

struct Int2 {
    int x{ 0 };
    int y{0};
};

struct Pixel {
    uint8_t r{ 0 };
    uint8_t g{ 0 };
    uint8_t b{ 0 };
    uint8_t a{ 0 };
};

#endif // WUTYPE_H