#include "vector.h"
#include <stdlib.h>

Vector* vectorCreate(size_t size)
{
    Vector *vector = malloc(sizeof(int) * size);
    return vector;
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
/*
ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res)
{
    return vector[index].data;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, int value)
{

    vector[index].data = value;
}
*/

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
    for (;i<vector->size;i++) {
        if(vector[i].data == value)
        {
            ++count;
        }
    }
    return count;
}
