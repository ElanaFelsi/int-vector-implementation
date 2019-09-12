#include "testing.h"
#include <stdio.h>
Vector *vector1, *vector3;
void vectorAlloc()
{
    printf(">>>>>>>>>>>>>  ALLOCATE  <<<<<<<<<<<<<\n");
    /* Vector *vector1 */
    vector1 = vectorCreate(5);
    Vector *vector2 = vectorCreate(10);
    vector3 = vectorCreate(2);
    Vector *vector4 = vectorCreate(0);
    /* Vector *vector5 = vectorCreate(-1); */

    vectorPrint(vector1);
    vectorPrint(vector4);
    /* vectorPrint(vector5); */

    vectorDestroy(&vector2);
    vectorDestroy(&vector4);


}

void vectorAddElem()
{
    printf(">>>>>>>>>>>>>  ADD  <<<<<<<<<<<<<\n");
    vectorPush(vector1,1);
    vectorPush(vector1,2);
    vectorPush(vector3,3);
    vectorPush(vector1,4);

    printf("-----vector1-----\n");
    vectorPrint(vector1);
    printf("-----vector3-----\n");
    vectorPrint(vector3);
    printf("-----vector3 when over capacity-----\n");
    vectorPush(vector3,3);
    vectorPush(vector3,3);
    vectorPrint(vector3);
}

void vectorInsertElem()
{
    printf(">>>>>>>>>>>>>  INSERT  <<<<<<<<<<<<<\n");

    printf("-----Print before insert-----\n");
    vectorPrint(vector1);
    vectorInsert(vector1,5,0);
    printf("-----Print after insert-----\n");
    vectorPrint(vector1);

    printf("-----Print before insert-----\n");
    vectorPrint(vector3);
    vectorInsert(vector3,5,6);
    printf("-----Print after insert-----\n");
    vectorPrint(vector3);

    printf("-----Print before insert-----\n");
    vectorPrint(vector3);
    vectorInsert(vector3,5,1);
    printf("-----Print after insert-----\n");
    vectorPrint(vector3);
}

void vectorPopLast()
{
    printf(">>>>>>>>>>>>>  POP  <<<<<<<<<<<<<\n");
    int info;
    int *res = &info;
    printf("-----Print before pop-----\n");
    vectorPrint(vector1);
    /* vectorPop(vector1, (int *) &res); why can i only do this way?? */
    vectorPop(vector1, res);
    printf("-----Print after pop-----\n");
    vectorPrint(vector1);
    /*printf("%d", *res); */
}
void vectorRemoveAny()
{
    printf(">>>>>>>>>>>>>  REMOVE  <<<<<<<<<<<<<\n");
    int info;
    int *res = &info;

    vectorRemove(vector1, 1, res);
    vectorPrint(vector1);

    vectorRemove(vector1, 5, res);
    vectorPrint(vector1);

    vectorRemove(vector1, 0, res);
    vectorPrint(vector1);

}
void vectorGetAnElement()
{
    printf(">>>>>>>>>>>>>  GET ELEMENT  <<<<<<<<<<<<<\n");
    int *res = 0;
    vectorGetElement(vector3, 12, res);
}
void vectorSetAnElement()
{

}
void vectorCountValue()
{
    printf(">>>>>>>>>>>>>  COUNT VALUE  <<<<<<<<<<<<<\n");
    printf("%zu\n",vectorCount(vector3, 3));
}

void vectorDest()
{
    printf(">>>>>>>>>>>>>  Destroy Vectors  <<<<<<<<<<<<<\n");

    vectorDestroy(&vector1);
    vectorDestroy(&vector3);
}

void test()
{
    vectorAlloc();
    vectorAddElem();
    vectorInsertElem();
    vectorPopLast();
    vectorRemoveAny();
    vectorCountValue();
    vectorDest();
}
