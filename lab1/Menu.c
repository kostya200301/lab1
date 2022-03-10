#include <stdio.h>
#include "main.c"




struct Vector* GenerateInput(int comand, int Size) {
    if (comand == 1){ //Если int
        struct RingInfo * ringInfo = CreateRingInfo(sizeof(int), IntSum, IntMult, PrintInt, IntZero(), IntOne());
        int * elements1 = malloc(sizeof(int) * Size);
        int i;
        for (i = 0; i < Size; i++){
            void* gen = GenInt();
            memcpy(elements1 + i, gen, sizeof(int));
            free(gen);
        }
        struct Vector* v1 = CreateVector(ringInfo, Size, (void *)elements1);
        return v1;
    }
    else if (comand == 2){ //Если Дабл
        struct RingInfo * ringInfo = CreateRingInfo(sizeof(double ), DoubleSum, DoubleMult, PrintDouble, DoubleZero(), DoubleOne());
        double * elements1 = malloc(sizeof(double ) * Size);
        int i;
        for (i = 0; i < Size; i++){
            void* gen = GenDouble();
            memcpy(elements1 + i, gen, sizeof(double));
            free(gen);
        }
        struct Vector* v1 = CreateVector(ringInfo, Size, (void *)elements1);
        return v1;
    }
    else if (comand == 3){ //Если Complex
        struct RingInfo * ringInfo = CreateRingInfo(sizeof(struct ComplexNumber), ComplexSum, ComplexMult, PrintComplex, ComplexZero(), ComplexOne());
        struct ComplexNumber* elements1 = malloc(sizeof(struct ComplexNumber) * Size);
        int i;
        for (i = 0; i < Size; i++){
            void* gen = GenComplex();
            memcpy(elements1 + i, gen, sizeof(struct ComplexNumber));
            free(gen);
        }
        struct Vector* v1 = CreateVector(ringInfo, Size, (void *)elements1);
        return v1;
    }
}


struct Vector* ConsoleInput(int comand, int Size){
    if (comand == 1){ //Если int
        struct RingInfo * ringInfo = CreateRingInfo(sizeof(int), IntSum, IntMult, PrintInt, IntZero(), IntOne());
        int * elements1 = malloc(sizeof(int) * Size);
        int i;
        for (i = 0; i < Size; i++){
            printf("Wright number: ");
            scanf("%d", elements1 + i);
        }
        struct Vector* v1 = CreateVector(ringInfo, Size, (void *)elements1);
        return v1;
    }
    else if (comand == 2){ //Если Double
        struct RingInfo * ringInfo = CreateRingInfo(sizeof(double ), DoubleSum, DoubleMult, PrintDouble, DoubleZero(), DoubleOne());
        double * elements1 = malloc(sizeof(double ) * Size);
        int i;
        for (i = 0; i < Size; i++){
            printf("Wright number: ");
            scanf("%lf", elements1 + i);
        }
        struct Vector* v1 = CreateVector(ringInfo, Size, (void *)elements1);
        return v1;
    }
    else if (comand == 3){ //Если комплексные
        struct RingInfo * ringInfo = CreateRingInfo(sizeof(struct ComplexNumber), ComplexSum, ComplexMult, PrintComplex, ComplexZero(), ComplexOne());
        struct ComplexNumber* elements1 = malloc(sizeof(struct ComplexNumber) * Size);
        int i;
        for (i = 0; i < Size; i++){
            printf("Wright number x, y: ");
            scanf("%d", &((elements1 + i)->x));
            scanf("%d", &((elements1 + i)->y));
        }
        struct Vector* v1 = CreateVector(ringInfo, Size, (void *)elements1);
        return v1;
    }
    return NULL;

}

struct Vector* GetVector(int com, int Size){
    printf("1 - Wright vector\n");
    printf("2 - Zero vector\n");
    printf("3 - One vector\n");


    int type;
    struct Vector* v1;
    scanf("%d", &type);
    if (type == 2){
        struct RingInfo* ringInfo = NULL;
        if (com == 1){
            ringInfo = CreateRingInfo(sizeof(int), IntSum, IntMult, PrintInt, IntZero(), IntOne());
        }
        else if (com == 2){
            ringInfo = CreateRingInfo(sizeof(double), DoubleSum, DoubleMult, PrintDouble, DoubleZero(), DoubleOne());
        }
        else{
            ringInfo = CreateRingInfo(sizeof(struct ComplexNumber), ComplexSum, ComplexMult, PrintComplex, ComplexZero(), ComplexOne());
        }
        v1 = CreateZeroVector(ringInfo, Size);
    }
    else if (type == 3){
        struct RingInfo* ringInfo = NULL;
        if (com == 1){
            ringInfo = CreateRingInfo(sizeof(int), IntSum, IntMult, PrintInt, IntZero(), IntOne());
        }
        else if (com == 2){
            ringInfo = CreateRingInfo(sizeof(double), DoubleSum, DoubleMult, PrintDouble, DoubleOne(), DoubleOne());
        }
        else{
            ringInfo = CreateRingInfo(sizeof(struct ComplexNumber), ComplexSum, ComplexMult, PrintComplex, ComplexZero(), ComplexOne());
        }
        v1 = CreateOneVector(ringInfo, Size);
    }
    else{
        v1 = ConsoleInput(com, Size);
    }
    return v1;
}

void init(int comand){
    struct Vector* v1 = NULL;
    struct Vector* v2 = NULL;
    int Size;
    if (comand == 1) {
        while (1) {
            printf("1 - Console input vectors\n");
            printf("2 - Generate vectors\n");
            printf("3 - Sum vectors\n");
            printf("4 - Scalar multiplay vectors\n");
            printf("5 - Wright vectors\n");
            printf("6 - Finish programm\n");
            int com;
            scanf("%d", &com);
            if (com == 1) {
                if (v1 != NULL){ //Если вызываем не 1 раз, то очищаем стрые векторы
                    FreeRingInfo(v1->ringInfo);
                    FreeRingInfo(v2->ringInfo);
                    FreeVector(v1);
                    FreeVector(v2);
                }
                printf("1 - Int vectors\n");
                printf("2 - Double vectors\n");
                printf("3 - Complecs vectors\n");
                scanf("%d", &com);
                printf("Wright vector size: ");
                scanf("%d", &Size);
                printf("First vector: \n");
                v1 = GetVector(com, Size);
                printf("Second vector: \n");
                v2 = GetVector(com, Size);
            } else if (com == 2) {
                if (v1 != NULL){ //Если вызываем не 1 раз, то очищаем стрые векторы
                    FreeRingInfo(v1->ringInfo);
                    FreeRingInfo(v2->ringInfo);
                    FreeVector(v1);
                    FreeVector(v2);
                }
                printf("1 - Int vectors\n");
                printf("2 - Double vectors\n");
                printf("3 - Complecs vectors\n");
                scanf("%d", &com);
                printf("Wright vector size: ");
                scanf("%d", &Size);
                v1 = GenerateInput(com, Size);
                v2 = GenerateInput(com, Size);

            } else if (com == 3) {
                if (v1 == NULL || v2 == NULL) {
                    printf("ERROR\n");
                    return;
                }
                struct Vector* SVec = Sum(v1, v2);
                Print(SVec);
                FreeVector(SVec);
            }
            else if (com == 4) {
                if (v1 == NULL || v2 == NULL) {
                    printf("ERROR\n");
                    return;
                }
                void * mult = ScalarMult(v1, v2);
                v1->ringInfo->PrintEl(mult);
                printf("\n");
                free(mult);
            }
            else if (com == 5) {
                if (v1 == NULL || v2 == NULL) {
                    printf("ERROR\n");
                    return;
                }
                Print(v1);
                Print(v2);
            }
            else {
                if (v1 != NULL){
                    FreeRingInfo(v1->ringInfo);
                    FreeRingInfo(v2->ringInfo);
                    FreeVector(v1);
                    FreeVector(v2);
                }
                return;
            }
        }
    } else if (comand == 2){

        struct RingInfo* ringinfo;
        ringinfo = CreateRingInfo(sizeof(int), IntSum, IntMult, PrintInt, IntZero(), IntOne());

        Test(ringinfo, GenInt, PrintIntFile);

        struct RingInfo* ringinfo2;
        ringinfo2 = CreateRingInfo(sizeof(double ), DoubleSum, DoubleMult, PrintDouble, DoubleZero(), DoubleOne());


        Test(ringinfo2, GenDouble, PrintDoubleFile);

        struct RingInfo* ringinfo3;
        ringinfo3 = CreateRingInfo(sizeof(struct ComplexNumber), ComplexSum, ComplexMult, PrintComplex, ComplexZero(), ComplexOne());


        Test(ringinfo3, GenComplex, PrintComplexFile);
        FreeRingInfo(ringinfo);
        FreeRingInfo(ringinfo2);
        FreeRingInfo(ringinfo3);

    } else{
        return;
    }

}


int main(){
    srand(time(NULL));

    while (1){
        printf("Hello, its Vector!\n");
        printf("1 - Create vectors\n");
        printf("2 - Test vectors\n");
        printf("3 - End programm\n");
        int comand;
        scanf("%d", &comand);
        init(comand);
        return 0;
    }
}