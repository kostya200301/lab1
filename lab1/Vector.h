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

struct Vector* CreateZeroVector(struct RingInfo* ringInfo, int N){
    struct Vector* vec = malloc(sizeof(struct Vector));
    vec->ringInfo = ringInfo;
    vec->N = N;
    vec->elements = malloc(ringInfo->size * N);
    for (int i = 0; i < N; i++){
        memcpy(vec->elements + i * ringInfo->size, ringInfo->zero, ringInfo->size);
    }

    return vec;
}

struct Vector* CreateOneVector(struct RingInfo* ringInfo, int N){
    struct Vector* vec = malloc(sizeof(struct Vector));
    vec->ringInfo = ringInfo;
    vec->N = N;
    vec->elements = malloc(ringInfo->size * N);
    for (int i = 0; i < N; i++){
        memcpy(vec->elements + i * ringInfo->size, ringInfo->one, ringInfo->size);
    }

    return vec;
}


void FreeVector(struct Vector* vector1){
    free(vector1->elements);
    free(vector1);
}

void Print(struct Vector *vec){
    int i;
    printf("{");
    for (i = 0; i < vec->N - 1; i++){
        vec->ringInfo->PrintEl(vec->elements + i * vec->ringInfo->size);
        printf(", ");
    }
    vec->ringInfo->PrintEl(vec->elements + i * vec->ringInfo->size);
    printf("}\n");
}

void* GetElement(struct Vector* vect, int index){
    return vect + index * vect->ringInfo->size;
}


struct Vector* Sum(struct Vector* vector1, struct Vector* vector2) // более "семантично"
{
    struct Vector* result = malloc(sizeof(struct Vector));
    result->ringInfo = vector1->ringInfo;
    result->N = vector1->N;
    int i;
    result->elements = malloc(sizeof(result->ringInfo->size) * result->N);
    for (i = 0; i < result->N; i++){
        void* el = result->ringInfo->sum((vector1->elements) + i * vector1->ringInfo->size, (vector2->elements) + i * vector2->ringInfo->size);
        memcpy((result->elements) + i * (result->ringInfo->size), el, sizeof(result->ringInfo->size));
        free(el);
    }
    return result;
}


void* ScalarMult(struct Vector* vector1, struct Vector* vector2) {
    if (vector1->N < 1){
        struct Vector* result = malloc(sizeof(struct Vector));
        result->ringInfo = vector1->ringInfo;
        result->N = vector1->N;
        result->elements = NULL;
        return result;
    }
    void* result = vector1->ringInfo->mul(vector1->elements, vector2->elements);
    int i;
    for (i = 1; i < vector1->N; i++){
        void* multip = vector1->ringInfo->mul(vector1->elements + i * vector1->ringInfo->size, vector2->elements + i * vector2->ringInfo->size);
        void* result2 = vector1->ringInfo->sum(result, multip);
        free(multip);
        free(result);
        result = result2;

    }
    return result;
}

