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

void* IntMult(void* el1, void* el2){
    int* first = (int*)el1;
    int* second = (int*)el2;
    int* res = malloc(sizeof(int));
    *res = *first * *second;
    return (void*)res;
}

void* DoubleSum(void* el1, void* el2){
    double* first = (double*)el1;
    double* second = (double*)el2;
    double* res = malloc(sizeof(double));
    *res = *first + *second;
    return (void*)res;
}

void* DoubleMult(void* el1, void* el2){
    double* first = (double*)el1;
    double* second = (double*)el2;
    double* res = malloc(sizeof(double));
    *res = *first * *second;
    return (void*)res;
}

void* ComplexSum(void* el1, void* el2){
    struct ComplexNumber* first = (struct ComplexNumber*)el1;
    struct ComplexNumber* second = (struct ComplexNumber*)el2;
    struct ComplexNumber* res = malloc(sizeof(struct ComplexNumber));
    res = SumComplexNumbers(first, second);
    return (void*)res;
}

void* ComplexMult(void* el1, void* el2){
    struct ComplexNumber* first = (struct ComplexNumber*)el1;
    struct ComplexNumber* second = (struct ComplexNumber*)el2;
    struct ComplexNumber* res = malloc(sizeof(struct ComplexNumber));
    res = MulComplexNumbers(first, second);
    return (void*)res;
}




void PrintComplex(void* n){
    struct ComplexNumber* element = (struct ComplexNumber*) n;
    printf("%d + %di", element->x, element->y);
}


void PrintDouble(void* n){
    double* element = (double *) n;
    printf("%f", *element);
}

void PrintInt(void* n){
    int* element = (int *) n;
    printf("%d", *element);
}



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


int main() {
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
