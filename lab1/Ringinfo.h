#pragma once
#include <stdio.h>

struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*);
    void* (*mul)(void*, void*);
    void (*PrintEl)(void*);
    void* zero;
    void* one;
};


void FreeRingInfo(struct RingInfo* ringInfo){
    free(ringInfo->zero);
    free(ringInfo->one);
    free(ringInfo);
}

struct RingInfo* CreateRingInfo(
        size_t size,
        void* (*sum)(void*, void*),
        void* (*mul)(void*, void*),
        void (*PrintEl)(void*),
        void* zero,
        void* one)
{
    struct RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
    ringInfo->size = size;
    ringInfo->sum = sum;
    ringInfo->mul = mul;
    ringInfo->PrintEl = PrintEl;
    ringInfo->zero = zero;
    ringInfo->one = one;
}