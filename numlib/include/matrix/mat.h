#pragma once

#define NUMLIB_GEN_FIXED_MATRIX(name, size, type)                           \
typedef struct                                                              \
{                                                                           \
    type arr[size][size];                                                   \
} numlib_##name;                                                            \
                                                                            \
static inline numlib_##name numlib_##name##_identity()                      \
{                                                                           \
    numlib_##name m = { 0 };                                                \
    for (int i = 0; i < size; i++)                                          \
        m.arr[i][i] = (type) 1;                                             \
    return m;                                                               \
}                                                                           \
                                                                            \
static inline numlib_##name numlib_##name##_mult(const numlib_##name* a,    \
                                                const numlib_##name* b)     \
{                                                                           \
    numlib_##name m = { 0 };                                                \
    for (int i = 0; i < size; i++)                                          \
        for (int j = 0; j < size; j++)                                      \
            for (int k = 0; k < size; k++)                                  \
                m.arr[i][j] += a->arr[i][k] * b->arr[k][j];                 \
    return m;                                                               \
}
