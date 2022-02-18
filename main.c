#include <stdio.h>
#include <malloc.h>
#include "Vector.h"
#include "Ringinfo.h"
#include "Complex.h"


void vivod(int * vec, size_t n){
    int i = 0;
    for (i = 0; i < n; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void* IntSum(void* el1, void* el2){
    int* first = (int*)el1;
    int* second = (int*)el2;
    int* res = malloc(sizeof(int));
    *res = *first + *second;
    return (void*)res;
}

void* ComplexSum(void* el1, void* el2){
    struct ComplexNumber* first = (struct ComplexNumber*)el1;
    struct ComplexNumber* second = (struct ComplexNumber*)el2;
    struct ComplexNumber* res = malloc(sizeof(struct ComplexNumber));
    res = SumComplexNumbers(first, second);
    return (void*)res;
}

void PrintComplexList(struct ComplexNumber* mas, int N){
    int i;
    for (i = 0; i < N; i++){
        printf("%d) %d + %di\n", i + 1, mas[i].x, mas[i].y);
    }
}

int main(){

    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(struct ComplexNumber);
    ringinfo->sum = ComplexSum;

    int i;
    int N = 5;
    struct ComplexNumber* mas1 = malloc(sizeof(struct ComplexNumber) * N);
    struct ComplexNumber* mas2 = malloc(sizeof(struct ComplexNumber) * N);
    for (i = 0; i < N; i++){
        mas1[i].x = rand() % 100;
        mas1[i].y = rand() % 100;
        mas2[i].x = rand() % 100;
        mas2[i].y = rand() % 100;
    }
    struct Vector* vec1 = CreateVector(ringinfo, N, mas1);
    struct Vector* vec2 = CreateVector(ringinfo, N, mas2);
    struct Vector* vec3 = Sum(vec1, vec2);
    PrintComplexList(vec1->elements, N);
    PrintComplexList(vec2->elements, N);
    PrintComplexList(vec3->elements, N);
    return 0;
}


int main2() {
    struct Vector vec;
    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(int);
    ringinfo->sum = IntSum;
    vec.N = 6;
    int* mas1 = malloc(sizeof(int) * 6);
    mas1[0] = 1;
    mas1[1] = 2;
    mas1[2] = 3;
    mas1[3] = 4;
    mas1[4] = 5;
    mas1[5] = 5;
    int* mas2 = malloc(sizeof(int) * 6);
    mas2[0] = 5;
    mas2[1] = 4;
    mas2[2] = 3;
    mas2[3] = 2;
    mas2[4] = 5;
    mas2[5] = 5;
    struct Vector* vec1 = malloc(sizeof(struct Vector));
    vec1->N = 6;
    vec1->elements = mas1;
    vec1->ringInfo = ringinfo;
    struct Vector* vec2 = malloc(sizeof(struct Vector));
    vec2->N = 6;
    vec2->elements = mas2;
    vec2->ringInfo = ringinfo;

    struct Vector* mas3= Sum(vec1, vec2);
    vivod(vec1->elements, 6);
    vivod(vec2->elements, 6);
    vivod(mas3->elements, 6);

    FreeVector(vec1);
    FreeVector(vec2);
    FreeVector(mas3);
    free(ringinfo);
    return 0;
}
