#pragma once
#include <stdio.h>
#include <malloc.h>

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
    struct ComplexNumber* res = SumComplexNumbers(first, second);
    return (void*)res;
}

void* ComplexMult(void* el1, void* el2){
    struct ComplexNumber* first = (struct ComplexNumber*)el1;
    struct ComplexNumber* second = (struct ComplexNumber*)el2;
    struct ComplexNumber* res = MulComplexNumbers(first, second);
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

void PrintIntFile(void* n, FILE *fp){
    int* element = (int *) n;
    fprintf(fp,"%d", *element);
}

void PrintDoubleFile(void* n, FILE *fp){
    double * element = (double *) n;
    fprintf(fp,"%f", *element);
}


void PrintComplexFile(void* n, FILE *fp){
    struct ComplexNumber* element = (struct ComplexNumber*) n;
    fprintf(fp, "%d + %di", element->x, element->y);
}

void * IntZero(){
    int num = 0;
    void* NumAdress = malloc(sizeof(int));
    memcpy(NumAdress, &num, sizeof(int));
    return NumAdress;
}

void * DoubleZero(){
    double num = 0.0;
    void* NumAdress = malloc(sizeof(double));
    memcpy(NumAdress, &num, sizeof(double));
    return NumAdress;
}

void * ComplexZero(){
    struct ComplexNumber* num = malloc(sizeof(struct ComplexNumber));
    num->x = 0;
    num->y = 0;
    return num;
}

void * IntOne(){
    int num = 1;
    void* NumAdress = malloc(sizeof(int));
    memcpy(NumAdress, &num, sizeof(int));
    return NumAdress;
}

void * DoubleOne(){
    double num = 1.0;
    void* NumAdress = malloc(sizeof(double));
    memcpy(NumAdress, &num, sizeof(double));
    return NumAdress;
}

void * ComplexOne(){
    struct ComplexNumber* num = malloc(sizeof(struct ComplexNumber));
    num->x = 1;
    num->y = 0;
    return num;
}