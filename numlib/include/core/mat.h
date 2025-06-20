#pragma once
#include <stddef.h>
#include "numlib.h"

/**
 * @brief Represents a floating-point matrix.
 */
typedef struct
{
    float* arr;     /** Pointer to dynamically allocated array of matrix. */
    size_t rows;    /** Number of rows of matrix. */
    size_t cols;    /** Number of columns of matrix. */
} numlib_matf_t;

/**
 * @brief Multiplies a mxn matrix a with a nxp matrix b.
 * 
 * @param ah - The amount of rows of matrix a.
 * @param aw - The amount of columns of matrix a.
 * @param bw - The amount of rows of matrix b.
 * @param bh - The amount of columns of matrix b.
 * 
 * @param a - Pointer to the array of matrix a.
 * @param b - Pointer to the array of matrix b.
 * @param c - Pointer to the array of result matrix c.
 * 
 * @return numlib_error_t - NUMLIB_SUCCESS on success, or
 *      NUMLIB_ERR_SIZE_MISMATCH on incompatible matrix size,
 *      or NUMLIB_ERR_INVALID_MAT_ARR on invalid array pointer.
 */
numlib_error_t numlib_matf_multiply(
    size_t ah,
    size_t aw,
    size_t bh,
    size_t bw,
    float* a,
    float* b,
    float* c
);

/**
 * @brief Generates identity matrix.
 * 
 * @param ah - The amount of rows of matrix a.
 * @param aw - The amount of columns of matrix a.
 * @param a - Pointer to the array of matrix a.
 * 
 * @return numlib_error_t - NUMLIB_SUCCES on success, or
 *      NUMLIB_ERR_INVALID_MAT_ARR on invalid array pointer.
 */
numlib_error_t numlib_matf_identity(
    size_t ah,
    size_t aw,
    float* a
);

/**
 * @brief Macro for generating fixed size matrices and functions.
 */
#define NUMLIB_MATF_FIXED(dim, name)                                                                \
                                                                                                    \
typedef struct                                                                                      \
{                                                                                                   \
    float arr[dim * dim];                                                                           \
} numlib_##name##_t;                                                                                \
                                                                                                    \
inline static numlib_error_t numlib_##name##_mult(                                                  \
    numlib_##name##_t* a,                                                                           \
    numlib_##name##_t* b,                                                                           \
    numlib_##name##_t* c                                                                            \
) {                                                                                                 \
    return numlib_matf_multiply(dim, dim, dim, dim, a->arr, b->arr, c->arr);                        \
}                                                                                                   \
                                                                                                    \
inline static numlib_error_t numlib_##name##_identity(                                              \
    numlib_##name##_t* a                                                                            \
) {                                                                                                 \
    return numlib_matf_identity(dim, dim, a->arr);                                                  \
}