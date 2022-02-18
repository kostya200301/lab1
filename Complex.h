#pragma once
#include <stdio.h>
#include <malloc.h>

struct ComplexNumber{
    int x;
    int y;
};

struct ComplexNumber* SumComplexNumbers(struct ComplexNumber *n1, struct ComplexNumber *n2){
    struct ComplexNumber* number = malloc(sizeof(struct ComplexNumber));
    number->x = n1->x + n2->x;
    number->y = n1->y + n2->y;
    return number;
}

struct ComplexNumber* MulComplexNumbers(struct ComplexNumber *n1, struct ComplexNumber *n2){
    struct ComplexNumber* number = malloc(sizeof(struct ComplexNumber));
    number->x = n1->x * n2->x - n1->y * n2->y;
    number->y = n1->x * n2->y + n2->x * n1->y;
    return number;
}
void PrintComplexNumber(struct ComplexNumber *n){
    printf("%d + %di\n", n->x, n->y);
}

