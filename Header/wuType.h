#pragma once
#ifndef WUTYPE_H
#define WUTYPE_H
#include <cstdint>

enum wuResult {
    WUR_NONE,
    WUR_QUIT
};
// [=]<-------------------------------------------------------------->[=]

struct Float2 {
    float x{ 0 };
    float y{ 0 };
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