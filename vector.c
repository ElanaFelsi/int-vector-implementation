#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

Vector* vectorCreate(size_t size)
{
    /*
    if(size < 0)
        return E_ALLOCATION_ERROR; */
    Vector *vector = malloc(sizeof(Vector));
    vector->data =  malloc(sizeof(int) * size);
    vector->capacity = size;
    return vector;
}

void vectorDestroy(Vector **vector)
{
    free(*vector);
}

void vectorCopy(Vector *vecDst, Vector *vecSrc, size_t begin, size_t end)
{
    while(begin <= end)
    {
        vecDst->data[begin+1] = vecSrc->data[begin];
        ++begin;
    }
}

void vectorResize(Vector *vector, size_t size)
{
    int *data = realloc(vector->data, sizeof(int) * size);
    if (data)
    {
        vector->data = data;
        vector->capacity = size;
    }
}

ErrorCode vectorPush(Vector *vector, int value)
{
    if(vector->size == vector->capacity)
    {
        vectorResize(vector, vector->capacity * 2);
    }
    /* Q. why cant I do ++size ? */
    vector->data[vector->size++] = value;
    return E_OK;
}

ErrorCode vectorInsert(Vector *vector, int value, size_t index)
{
    if(index >= vector->size)
    {
        return E_BAD_INDEX;
    }
    if(vector->size == vector->capacity)
    {
        vectorResize(vector, vector->capacity * 2);
    }
    Vector *v =vectorCreate(vector->capacity);
    size_t i=0;
    vectorCopy(v, vector, index, vector->size);
    vector->data[index] = value;
    vectorCopy(vector, v, index+1, v->size);
    return E_OK;
}

ErrorCode vectorPop(Vector *vector, int *res)
{
    res = &vector->data[vector->size];

    vector->data[vector->size] = (int) NULL;

    vector->size--;
}

ErrorCode vectorRemove(Vector *vector, size_t index, int *res)
{
    if(index >= vector->size)
    {
        return E_BAD_INDEX;
    }
    res = &vector->data[index];

    vector->data[index] = (int) NULL;
    size_t i, j;
    int *holdData = malloc(sizeof(int) * vector->size);
    for(i = 0, j = 0; i < vector->size; i++)
    {
        if(vector->data[i])
        {
            holdData[j] = vector->data[i];
            j++;
        }
    }
    free(vector->data);

    vector->data = holdData;
    vector->size--;

}

ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res)
{
    if(index >= vector->size)
    {
        return E_BAD_INDEX;
    }
    res = &vector->data[index];
    return E_OK;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, int value)
{
    if(index >= vector->size)
    {
        return E_BAD_INDEX;
    }
    vector->data[index] = value;
    return E_OK;
}


size_t vectorGetSize(const Vector *vector)
{
    return vector->size;
}

size_t vectorGetCapacity(const Vector *vector)
{
    return vector->capacity;
}

size_t vectorCount(const Vector *vector, int value)
{
    int i=0;
    size_t count=0;
    for (;i < vector->size;i++) {
        if(vector->data[i] == value)
        {
            ++count;
        }
    }
    return count;
}

void vectorPrint(Vector *vector)
{
    printf("capacity= %zu\n", vector->capacity );
    printf("size= %zu\n", vector->size );
    size_t i=0;
    printf("data: ");
    for(;i < vectorGetSize(vector); i++)
    {
        printf("%d, ", vector->data[i]);
    }
    printf("\n");
}
