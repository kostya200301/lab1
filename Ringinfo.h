#pragma once
#include <stdio.h>

struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*mul)(void*, void*);
    void (*PrintEl)(void*);
    //void* zero;
    //void* (*minus)(void*);
    //void* (*mult)(void*, void*);
    //void* one;
};