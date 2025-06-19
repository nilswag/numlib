#include "matrix/mat.h"

numlib_error numlib_matf_multiply(const float* a, const float* b, int aw, int ah, int bw, int bh, float* result)
{
    if (aw != bh) return NUMLIB_ERR_SIZE_MISMATCH;
    
    for (int i = 0; i < aw; i++)
    {
        
    }

    return NUMLIB_SUCCESS;
}