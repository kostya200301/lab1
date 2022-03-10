#pragma once
#include <stdio.h>
#include <malloc.h>
#include "Vector.h"
#include "UserFuctions.h"
#include <string.h>





int SumEquals(void * m1, void * m2, size_t size, int n){
    if (memcmp(m1, m2, size * n) == 0){
        return 1;
    }
    return 0;
}

void* GenInt(){
    int gen_number1 = rand() % 1000;
    int* num = malloc(sizeof(int));
    *num = gen_number1;
    return (void*)num;
}

void* GenDouble(){
    double gen_number1 = (rand() % 1000) / 100.0;
    double* num = malloc(sizeof(double));
    *num = gen_number1;
    return (void*)num;
}

void* GenComplex(){

    struct ComplexNumber* num = malloc(sizeof(double));
    num->x = rand() % 100;
    num->y = rand() % 100;
    return (void*)num;
}




void FilePrint(FILE* fp, void* e1, void* e2, void*result, size_t ElSize, int status, int n, char name[15], void (*PrintElFile)(void*, FILE *fp)){


    if (status){
        fprintf(fp, "%s", "OK ");
    } else{
        fprintf(fp, "%s", "FAIL ");
    }

    fprintf(fp, "%s", "{");
    int i;
    for (i = 0; i < n - 1; i++){
        PrintElFile(e1 + i * ElSize, fp);
        fprintf(fp, "%s", ", ");
    }
    PrintElFile(e1 + i * ElSize, fp);
    fprintf(fp, "%s", "} + ");

    fprintf(fp, "%s", "{");
    for (i = 0; i < n - 1; i++){
        PrintElFile(e2 + i * ElSize, fp);
        fprintf(fp, "%s", ", ");
    }
    PrintElFile(e2 + i * ElSize, fp);
    fprintf(fp, "%s", "} = ");

    fprintf(fp, "%s", "{");
    for (i = 0; i < n - 1; i++){
        PrintElFile(result + i * ElSize, fp);
        fprintf(fp, "%s", ", ");
    }
    PrintElFile(result + i * ElSize, fp);
    fprintf(fp, "%s", "}\n");

}


// Not use
int test_sum_int(){
    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(int);
    ringinfo->sum = IntSum;
    ringinfo->mul = IntMult;
    ringinfo->PrintEl = PrintInt;


    int FileNumber = rand() % 100000;
    char s[6];
    sprintf(s, "%d", FileNumber);
    char name[15] = "TestRes";
    memcpy(name + 7, s, sizeof(char) * 6);
    FILE *fp;
    fp = fopen(name, "w");

    int first = 1;
    int second = 228;
    int GoodTests = 0;
    int BedTests = 0;
    int i;
    for (i = first; i <= second; i++){
        int * numbers1 = malloc(sizeof(int) * i);
        int * numbers2 = malloc(sizeof(int) * i);
        int * result = malloc(sizeof(int) * i);
        int j;
        for (j = 0; j < i; j++){
            int gen_number1 = rand() % 1000;
            int gen_number2 = rand() % 1000;
            numbers1[j] = gen_number1;
            numbers2[j] = gen_number2;
            result[j] = gen_number1 + gen_number2;
        }
        struct Vector* v1 = CreateVector(ringinfo, i, numbers1);
        struct Vector* v2 = CreateVector(ringinfo, i, numbers2);
        struct Vector* VResult = Sum(v1, v2);
        int answer = SumEquals(VResult->elements, result, VResult->ringInfo->size, i);

        if (answer){
            GoodTests++;
        } else{
            BedTests++;
        }



        FilePrint(fp, numbers1, numbers2, VResult->elements, ringinfo->size, BedTests == 0, i, name, PrintIntFile);


        free(result);
        FreeVector(v1);
        FreeVector(v2);
        FreeVector(VResult);
    }
    free(ringinfo);
    printf("%d tests passed, %d failed. File report 'TestRes%d'\n", GoodTests, BedTests, FileNumber);
    fclose(fp);
}
// Not use
int test_double_int(){
    struct RingInfo* ringinfo;
    ringinfo = malloc(sizeof(struct RingInfo));
    ringinfo->size = sizeof(double);
    ringinfo->sum = DoubleSum;
    ringinfo->mul = DoubleMult;
    ringinfo->PrintEl = PrintDouble;


    int FileNumber = rand() % 100000;
    char s[6];
    sprintf(s, "%d", FileNumber);
    char name[15] = "TestRes";
    memcpy(name + 7, s, sizeof(char) * 6);
    FILE *fp;
    fp = fopen(name, "w");

    int first = 1;
    int second = 228;
    int GoodTests = 0;
    int BedTests = 0;
    int i;
    for (i = first; i <= second; i++){
        double * numbers1 = malloc(sizeof(double) * i);
        double * numbers2 = malloc(sizeof(double) * i);
        double * result = malloc(sizeof(double) * i);
        int j;
        for (j = 0; j < i; j++){
            double gen_number1 = (rand() % 1000) / 100.0;
            double gen_number2 = (rand() % 1000) / 100.0;
            numbers1[j] = gen_number1;
            numbers2[j] = gen_number2;
            result[j] = gen_number1 + gen_number2;
        }
        struct Vector* v1 = CreateVector(ringinfo, i, numbers1);
        struct Vector* v2 = CreateVector(ringinfo, i, numbers2);
        struct Vector* VResult = Sum(v1, v2);
        double answer = SumEquals(VResult->elements, result, VResult->ringInfo->size, i);

        if (answer){
            GoodTests++;
        } else{
            BedTests++;
        }



        FilePrint(fp, numbers1, numbers2, VResult->elements, ringinfo->size, BedTests == 0, i, name, PrintDoubleFile);


        free(result);
        FreeVector(v1);
        FreeVector(v2);
        FreeVector(VResult);
    }
    free(ringinfo);
    printf("%d tests passed, %d failed. File report 'TestRes%d'\n", GoodTests, BedTests, FileNumber);
    fclose(fp);
}

int Test(struct RingInfo* ringinfo, void*(*generate)(), void (*PrintFunc)(void* n, FILE *fp)){
    int FileNumber = rand() % 100000;
    char s[6];
    sprintf(s, "%d", FileNumber);
    char name[15] = "TestRes";
    memcpy(name + 7, s, sizeof(char) * 6);
    FILE *fp;
    fp = fopen(name, "w");

    int first = 1;
    int second = 228;
    int GoodTests = 0;
    int BedTests = 0;
    int i;
    for (i = first; i <= second; i++){
        void * numbers1 = malloc(ringinfo->size * i);
        void * numbers2 = malloc(ringinfo->size * i);
        void * result = malloc(ringinfo->size * i);
        int j;
        for (j = 0; j < i; j++){
            void * gen_number1 = generate();
            void * gen_number2 = generate();
            memcpy(numbers1 + j * ringinfo->size, gen_number1, ringinfo->size);
            memcpy(numbers2 + j * ringinfo->size, gen_number2, ringinfo->size);
            void * sum1 = ringinfo->sum(gen_number1, gen_number2);
            memcpy(result + j * ringinfo->size, sum1, ringinfo->size);
            free(sum1);
            free(gen_number1);
            free(gen_number2);

        }
        struct Vector* v1 = CreateVector(ringinfo, i, numbers1);
        struct Vector* v2 = CreateVector(ringinfo, i, numbers2);
        struct Vector* VResult = Sum(v1, v2);
        int answer = SumEquals(VResult->elements, result, VResult->ringInfo->size, i);

        if (answer){
            GoodTests++;
        } else{
            BedTests++;
        }



        FilePrint(fp, numbers1, numbers2, VResult->elements, ringinfo->size, BedTests == 0, i, name, PrintFunc);


        free(result);
        FreeVector(v1);
        FreeVector(v2);
        FreeVector(VResult);
    }
    //free(ringinfo);
    printf("%d tests passed, %d failed. File report 'TestRes%d'\n", GoodTests, BedTests, FileNumber);
    fclose(fp);
}
