#pragma once
#ifndef WUTYPE_H
#define WUTYPE_H
#include <cstdint>

enum wuResult {
    WUR_NONE,
    WUR_QUIT
};
// [=]<-------------------------------------------------------------->[=]
struct Int2 {
    int x{ 0 };
    int y{ 0 };
};
struct UInt2 {
    uint32_t x{ 0 };
    uint32_t y{ 0 };
};
// [=]<-------------------------------------------------------------->[=]
struct Pixel {
    uint8_t r{ 0 };
    uint8_t g{ 0 };
    uint8_t b{ 0 };
    uint8_t a{ 0 };
};

#endif // WUTYPE_H
// [=]<-------------------------------------------------------------->[=]