#pragma once
#include "numlib.h"

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
 * @return numlib_error - NUMLIB_SUCCESS on success, or
 *      NUMLIB_ERR_SIZE_MISMATCH on incompatible matrix size.
 */
numlib_error numlib_matf_multiply(
    int ah,
    int aw,
    int bh,
    int bw,
    float* a,
    float* b,
    float* c
);
