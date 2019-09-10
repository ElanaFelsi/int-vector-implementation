#include "vector.h"

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
