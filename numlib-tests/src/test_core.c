#include <assert.h>
#include "core/mat.h"
#include "numlib.h"

void test_numlib_matf_identity(void)
{
    float mat[3 * 3];
    numlib_error_t err = numlib_matf_identity(3, 3, mat);
    assert(err == NUMLIB_SUCCESS);

    float expected[9] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };
    for (int i = 0; i < 9; i++) {
        assert(mat[i] == expected[i]);
    }

    err = numlib_matf_identity(2, 2, NULL);
    assert(err == NUMLIB_ERR_INVALID_MAT_ARR);

    float nonsquare[2 * 3];
    err = numlib_matf_identity(2, 3, nonsquare);
    assert(err == NUMLIB_SUCCESS);

    assert(nonsquare[0] == 1.0f);
    assert(nonsquare[1] == 0.0f);
    assert(nonsquare[2] == 0.0f);
    assert(nonsquare[3] == 0.0f);
    assert(nonsquare[4] == 1.0f);
    assert(nonsquare[5] == 0.0f);
}

void test_numlib_matf_multiply(void)
{
    float a[2 * 3] = {
        1, 2, 3,
        4, 5, 6
    };
    float b[3 * 2] = {
        7, 8,
        9, 10,
        11, 12
    };
    float c[2 * 2];
    numlib_error_t err = numlib_matf_multiply(2, 3, 3, 2, a, b, c);
    assert(err == NUMLIB_SUCCESS);

    float expected[4] = {
        58, 64,
        139, 154
    };
    for (int i = 0; i < 4; i++) {
        assert(c[i] == expected[i]);
    }

    assert(numlib_matf_multiply(2, 3, 3, 2, NULL, b, c) == NUMLIB_ERR_INVALID_MAT_ARR);
    assert(numlib_matf_multiply(2, 3, 3, 2, a, NULL, c) == NUMLIB_ERR_INVALID_MAT_ARR);
    assert(numlib_matf_multiply(2, 3, 3, 2, a, b, NULL) == NUMLIB_ERR_INVALID_MAT_ARR);

    assert(numlib_matf_multiply(2, 3, 2, 2, a, b, c) == NUMLIB_ERR_SIZE_MISMATCH);

    float a1[1] = { 3 };
    float b1[1] = { 4 };
    float c1[1] = { 0 };
    err = numlib_matf_multiply(1, 1, 1, 1, a1, b1, c1);
    assert(err == NUMLIB_SUCCESS);
    assert(c1[0] == 12.0f);
}
