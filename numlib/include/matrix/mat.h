#pragma once
#include "numlib.h"

/**
 * @brief Multiplies a mxn matrix a with a nxp matrix b.
 * 
 * @param ah - The amount of rows of matrix a.
 * @param aw - The amount of columns of matrix a.
 * @param bw - The amount of rows of matrix b.
 * @param bh - The amount of columns of matrix b.
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
