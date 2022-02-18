#pragma once
#include <stdio.h>
#include <string.h>
#include "Ringinfo.h"



struct Vector{
    struct RingInfo* ringInfo;
    int N;
    void* elements;
};


struct Vector* CreateVector(struct RingInfo* ringInfo, int N, void * elements){
    struct Vector* vec = malloc(sizeof(struct Vector));
    vec->ringInfo = ringInfo;
    vec->N = N;
    vec->elements = elements;
    return vec;
}


void FreeVector(struct Vector* vector1){
    free(vector1->elements);
    free(vector1);
}

struct Vector* Sum(struct Vector* vector1, struct Vector* vector2) // более "семантично"
{
    //if (v1->ringInfo != v2->ringInfo) // надежнее через RingInfoEquals(v1->ringInfo,v2->ringInfo)
    // Добавить Сравнение Размеров
    struct Vector* result = malloc(sizeof(struct Vector));
    result->ringInfo = vector1->ringInfo;
    result->N = vector1->N;
    int i;
    result->elements = malloc(sizeof(result->ringInfo->size) * result->N);
    for (i = 0; i < result->N; i++){
        printf("ff\n");
        //void* el = result->ringInfo->sum((vector1->elements) + i * vector1->ringInfo->size, (vector2->elements) + i * vector2->ringInfo->size);
        void* el = result->ringInfo->sum((vector1->elements) + i * vector1->ringInfo->size, (vector2->elements) + i * vector2->ringInfo->size);
        memcpy((result->elements) + i * (result->ringInfo->size), el, sizeof(result->ringInfo->size));
        free(el);
    }
    return result;
}