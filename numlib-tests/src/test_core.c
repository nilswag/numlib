#include <assert.h>
#include <string.h>
#include <core/mat.h>
#include <core/matf2x2.h>

static void assert_float_array_eq(const float* a, const float* b, size_t count) {
    assert(memcmp(a, b, count * sizeof(float)) == 0);
}

void test_numlib_matf2x2_identity(void)
{
    numlib_matf2x2_t m = { 0 };
    numlib_matf2x2_t expected = { {1, 0, 0, 1} };
    numlib_matf2x2_identity(&m);
    assert_float_array_eq(m.arr, expected.arr, 4);
}

void test_numlib_matf2x2_mult(void)
{
    numlib_matf2x2_t a = { {1, 2, 3, 4} };
    numlib_matf2x2_t b = { {5, 6, 7, 8} };
    numlib_matf2x2_t res = { 0 };
    numlib_matf2x2_t expected = { {19, 22, 43, 50} };

    numlib_matf2x2_mult(&a, &b, &res);
    assert_float_array_eq(res.arr, expected.arr, 4);
}

void test_numlib_matf_identity(void)
{
    float mat[9];
    numlib_error_t err = numlib_matf_identity(3, 3, mat);
    assert(err == NUMLIB_SUCCESS);

    float expected[9] = {
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };
    assert_float_array_eq(mat, expected, 9);

    assert(numlib_matf_identity(2, 2, NULL) == NUMLIB_ERR_INVALID_MAT_ARR);

    float nonsquare[6];
    err = numlib_matf_identity(2, 3, nonsquare);
    assert(err == NUMLIB_SUCCESS);
    assert(nonsquare[0] == 1 && nonsquare[1] == 0 && nonsquare[2] == 0);
    assert(nonsquare[3] == 0 && nonsquare[4] == 1 && nonsquare[5] == 0);
}

void test_numlib_matf_multiply(void)
{
    float a[6] = { 1, 2, 3, 4, 5, 6 };
    float b[6] = { 7, 8, 9, 10, 11, 12 };
    float c[4] = { 0 };
    numlib_error_t err = numlib_matf_multiply(2, 3, 3, 2, a, b, c);
    assert(err == NUMLIB_SUCCESS);

    float expected[4] = { 58, 64, 139, 154 };
    assert_float_array_eq(c, expected, 4);

    assert(numlib_matf_multiply(2, 3, 3, 2, NULL, b, c) == NUMLIB_ERR_INVALID_MAT_ARR);
    assert(numlib_matf_multiply(2, 3, 3, 2, a, NULL, c) == NUMLIB_ERR_INVALID_MAT_ARR);
    assert(numlib_matf_multiply(2, 3, 3, 2, a, b, NULL) == NUMLIB_ERR_INVALID_MAT_ARR);
    assert(numlib_matf_multiply(2, 3, 2, 2, a, b, c) == NUMLIB_ERR_SIZE_MISMATCH);

    float a1[1] = { 3 }, b1[1] = { 4 }, c1[1] = { 0 };
    err = numlib_matf_multiply(1, 1, 1, 1, a1, b1, c1);
    assert(err == NUMLIB_SUCCESS);
    assert(c1[0] == 12);
}
