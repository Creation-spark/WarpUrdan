#pragma once
#ifndef WUTYPE_H
#define WUTYPE_H
#include <cstdint>

enum wuResult {
    WUR_SUCCESS,
    WUR_OK,
    WUR_FUCK,
    WUR_NONE,
    WUR_QUIT
};

struct Int2 {
    int x{ 0 };
    int y{ 0 };
};
struct UInt2 {
    uint32_t x{ 0 };
    uint32_t y{ 0 };
};

struct Pixel {
    uint8_t r{ 0 };
    uint8_t g{ 0 };
    uint8_t b{ 0 };
    uint8_t a{ 0 };
};

template< typename T>
class Vec{ // MAKE **
private:
    T* arr;
    int size{ 0 };
public:
    explicit Vec() {
    }
    explicit Vec(int Size) {
        if (Size > 0) {
            arr = new T[Size];
            size = Size;
        }
    }
    ~Vec() {
        delete[] arr;
    }
// [=]<------------------------------------------------------------->[=]
    T& operator[] (int index) {
        return arr[index];
    }
// [=]<------------------------------------------------------------->[=]
    int Size() { return size; }
    void Init() {
        arr = new T[size];
    }
    void Clear() {
        delete[] arr;
    }
    void Resize(int new_size) {
        if (new_size > 0) {
            delete[] arr;
            arr = new T[new_size];
            size = new_size;
        }
    }
};

#endif // WUTYPE_H

// [#-#-#-#-#-#-#-#-#-#-#-#-#-#-#>{ ... }<#-#-#-#-#-#-#-#-#-#-#-#-#-#-#]