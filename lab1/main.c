#include <stdio.h>
#include <malloc.h>
#include "Vector.h"
#include "Ringinfo.h"
#include "Complex.h"
#include "Tests.h"
#include <time.h>


int main3(){
    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(double);
    ringinfo->sum = DoubleSum;
    ringinfo->mul = DoubleMult;
    ringinfo->PrintEl = PrintDouble;



    int i;
    int N = 5;
    double* mas1 = malloc(sizeof(double) * N);
    double* mas2 = malloc(sizeof(double) * N);
    for (i = 0; i < N; i++){
        mas1[i] = (rand() % 1000) / 100.0;
        mas2[i] = (rand() % 1000) / 100.0;
    }
    struct Vector* vec1 = CreateVector(ringinfo, N, mas1);
    struct Vector* vec2 = CreateVector(ringinfo, N, mas2);
    struct Vector* vec3 = Sum(vec1, vec2);

    Print(vec1);
    Print(vec2);
    Print(vec3);
    void* scal = ScalarMult(vec1, vec2);
    printf("Skalar Mult = ");
    PrintDouble(scal);
    printf("\n");
}


int main2(){

    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(struct ComplexNumber);
    ringinfo->sum = ComplexSum;
    ringinfo->mul = ComplexMult;
    ringinfo->PrintEl = PrintComplex;

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
    Print(vec1);
    Print(vec2);
    Print(vec3);
    void* scal = ScalarMult(vec1, vec2);
    printf("Skalar Mult = ");
    PrintComplex(scal);
    printf("\n");
    return 0;
}


int main4() {
    struct Vector vec;
    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(int);
    ringinfo->sum = IntSum;
    ringinfo->mul = IntMult;
    ringinfo->PrintEl = PrintInt;

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



    Print(vec1);
    Print(vec2);
    Print(mas3);

    void* scal = ScalarMult(vec1, vec2);
    printf("Skalar Mult = ");
    PrintInt(scal);
    printf("\n");

    FreeVector(vec1);
    FreeVector(vec2);
    FreeVector(mas3);
    free(ringinfo);
    main2();
    main3();
    return 0;
}

int main7(){
    srand(time(NULL));

    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(int);
    ringinfo->sum = IntSum;
    ringinfo->mul = IntMult;
    ringinfo->PrintEl = PrintInt;

    Test(ringinfo, GenInt, PrintIntFile);

    struct RingInfo* ringinfo2;
    ringinfo2 = malloc(sizeof(struct RingInfo));
    ringinfo2->size = sizeof(double);
    ringinfo2->sum = DoubleSum;
    ringinfo2->mul = DoubleMult;
    ringinfo2->PrintEl = PrintDouble;

    Test(ringinfo2, GenDouble, PrintDoubleFile);

    struct RingInfo* ringinfo3;
    ringinfo3 = malloc(sizeof(struct RingInfo));
    ringinfo3->size = sizeof(struct ComplexNumber);
    ringinfo3->sum = ComplexSum;
    ringinfo3->mul = ComplexMult;
    ringinfo3->PrintEl = PrintComplex;

    Test(ringinfo3, GenComplex, PrintComplexFile);
    return 0;
}