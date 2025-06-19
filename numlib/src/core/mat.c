#include <stddef.h>
#include "numlib.h"
#include "core/mat.h"

numlib_error_t numlib_matf_multiply(
    size_t ah,
    size_t aw,
    size_t bh,
    size_t bw,
    float* a,
    float* b,
    float* c
) {
    if (a == NULL || b == NULL || c == NULL)
        return NUMLIB_ERR_INVALID_MAT_ARR;
    if (aw != bh)
        return NUMLIB_ERR_SIZE_MISMATCH;
    /*
        A: ah x aw (M x N)
        B: bh x bw (N x P) -> ah = bw
        C: ah x bw (M x N)
    */
    for (size_t i = 0; i < ah; i++) // rows (a & c)
    {
        for (size_t j = 0; j < bw; j++) // columns (b & c)
        {
            float sum = 0.0f; // reset value in c
            for (size_t k = 0; k < aw; k++)
            {
                //     a[i][k]      *  b[k][j]
                sum += a[i * aw + k] * b[k * bw + j];
            }
            c[i * bw + j] = sum;
        }
    }
    return NUMLIB_SUCCESS;
}

numlib_error_t numlib_matf_identity(
    size_t ah,
    size_t aw,
    float* a
) {
    if (a == NULL)
        return NUMLIB_ERR_INVALID_MAT_ARR;
    for (size_t i = 0; i < ah; i++)
    {
        for (size_t j = 0; j < aw; j++)
        {
            a[i * aw + j] = (i == j) ? 1.0f : 0.0f;
        }
    }
    return NUMLIB_SUCCESS;
}
