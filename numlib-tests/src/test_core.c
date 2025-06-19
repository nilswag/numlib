#include <assert.h>
#include "core/mat.h"
#include "numlib.h"

void test_numlib_matf_identity(void)
{
    float mat[3 * 3];
    numlib_error_t err = numlib_matf_identity(3, 3, mat);
    assert(err == NUMLIB_SUCCESS);

    float expected[3 * 3] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    for (int i = 0; i < 9; i++) {
        assert(mat[i] == expected[i]);
    }
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
}
