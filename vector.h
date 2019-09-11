#ifndef C_VECTOR_OF_INTS_ELANAFELSI_VECTOR_H
#define C_VECTOR_OF_INTS_ELANAFELSI_VECTOR_H

#include <stddef.h>

typedef enum
{
    E_OK,
    E_NULL_PTR,
    E_UNDERFLOW,
    E_ALLOCATION_ERROR,
    E_BAD_INDEX
} ErrorCode;

typedef struct Vector{
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector* vectorCreate(size_t size);
void vectorDestroy(Vector **vector);

void vectorCopy(Vector *vecDst, Vector *vecSrc,  size_t begin, size_t end);

void vectorResize(Vector *vector, size_t size);

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode vectorPush(Vector *vector, int value);

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode vectorInsert(Vector *vector, int value, size_t index);

/* Clears the item at the end */
ErrorCode vectorPop(Vector *vector, int *res);

/* Clears an item at a certain position and shifts. */
ErrorCode vectorRemove(Vector *vector, size_t index, int *res);

ErrorCode vectorGetElement(const Vector *vector, size_t index, int *res);
ErrorCode vectorSetElement(Vector *vector, size_t index, int value);

size_t vectorGetSize(const Vector *vector);
size_t vectorGetCapacity(const Vector *vector);

/* Counts how many instances of a given value there are. */
size_t vectorCount(const Vector *vector, int value);

#ifdef _DEBUG
void vectorPrint(Vector *vector);
#endif /* _DEBUG */


#endif //C_VECTOR_OF_INTS_ELANAFELSI_VECTOR_H
