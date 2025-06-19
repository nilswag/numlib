#include "core/mat.h"

numlib_error_t numlib_matf_multiply(
    int ah,
    int aw,
    int bh,
    int bw,
    float* a,
    float* b,
    float* c
) {
    if (aw != bh) return NUMLIB_ERR_SIZE_MISMATCH;
    /*
        A: ah x aw (M x N)
        B: bh x bw (N x P) -> ah = bw
        C: ah x bw (M x N)
    */
    for (int i = 0; i < ah; i++) // rows (a & c)
    {
        for (int j = 0; j < bw; j++) // columns (b & c)
        {
            float sum = 0.0f; // reset value in c
            for (int k = 0; k < aw; k++)
            {
                //     a[i][k]      *  b[k][j]
                sum += a[i * aw + k] * b[k * bw + j];
            }
            c[i * bw + j] = sum;
        }
    }
    return NUMLIB_SUCCESS;
}