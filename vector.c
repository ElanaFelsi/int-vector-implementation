#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Vector{
    int *m_data;
    size_t m_size;
    size_t m_capacity;
} Vector;


Vector* vectorCreate(size_t size)
{
    Vector *vector = malloc(sizeof(Vector));

    if(vector)
    {
        vector->m_capacity = size;
        vector->m_size = 0;
        vector->m_data =  malloc(sizeof(int) * size);

        if(!vector->m_data)
        {
            free(vector);
            vector = NULL;
        }
    }

    return vector;
}

void vectorDestroy(Vector **vector)
{
    if(vector && *vector) {
        free((*vector)->m_data);
        free(*vector);
        *vector = NULL;
    }
}

void vectorResize(Vector *vector, size_t size)
{
    int *data = realloc(vector->m_data, sizeof(int) * size);
    if (data)
    {
        vector->m_data = data;
        vector->m_capacity = size;
    }
}

ErrorCode vectorPush(Vector *vector, int value)
{
    if(!vector)
    {
        return E_NULL_PTR;
    }

    if(vector->m_size >= vector->m_capacity)
    {
        vectorResize(vector, vector->m_capacity * 2);
    }

    vector->m_data[vector->m_size++] = value;

    return E_OK;
}

ErrorCode vectorInsert(Vector *vector, int value, size_t index)
{
    if(index >= vector->m_size)
    {
        return E_BAD_INDEX;
    }

    if(index == vector->m_size)
    {
        return vectorPush(vector, value);
    }

    if(vector->m_size == vector->m_capacity)
    {
        vectorResize(vector, vector->m_capacity * 2);
    }
    size_t i = vector->m_size;
    for (; i > index; --i){
        vector->m_data[i] = vector->m_data[i-1];
    }
    vector->m_data[index] = value;
    ++vector ->m_size;
    return E_OK;
}

ErrorCode vectorPop(Vector *vector, int *res)
{
    if(vector->m_size == 0)
    {
        return E_NULL_PTR;
    }

    *res = vector->m_data[--vector->m_size];

    --vector->m_size;

    return E_OK;
}

ErrorCode vectorRemove(Vector *vector, size_t index, int *res)
{
    if(index >= vector->m_size)
    {
        return E_BAD_INDEX;
    }

    *res = vector->m_data[--index];

    size_t i, j;
    int *holdData = malloc(sizeof(int) * vector->m_size);
    for(i = 0, j = 0; i < vector->m_size; i++)
    {
        if(vector->m_data[i])
        {
            holdData[j] = vector->m_data[i];
            j++;
        }
    }
    free(vector->m_data);

    vector->m_data = holdData;
    --vector->m_size;

    return E_OK;

}

ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res)
{
    if(index >= vector->m_size)
    {
        return E_BAD_INDEX;
    }
    *res = vector->m_data[--index];
    return E_OK;
}

ErrorCode vectorSetElement(Vector *vector, size_t index, int value)
{
    if(index >= vector->m_size)
    {
        return E_BAD_INDEX;
    }
    vector->m_data[index] = value;
    return E_OK;
}


size_t vectorGetSize(const Vector *vector)
{
    return vector->m_size;
}

size_t vectorGetCapacity(const Vector *vector)
{
    return vector->m_capacity;
}

size_t vectorCount(const Vector *vector, int value)
{
    size_t i=0, count=0;
    size_t size = vectorGetSize(vector);
    for (;i < size;++i) {
        if(vector->m_data[i] == value)
        {
            ++count;
        }
    }
    return count;
}

void vectorPrint(const Vector *vector)
{
    printf("capacity= %zu\n", vector->m_capacity );
    printf("size= %zu\n", vector->m_size );
    size_t i=0;
    printf("data: ");
    for(;i < vectorGetSize(vector); i++)
    {
        printf("%d, ", vector->m_data[i]);
    }
    printf("\n");
}
