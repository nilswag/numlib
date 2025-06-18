#include <stdio.h>
#include <matrix/mat3x3f.h>

void print_float_matrix(const float* arr, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        printf("[");
        for (size_t j = 0; j < cols; ++j) {
            printf("%.3f", arr[i * cols + j]);
            if (j < cols - 1)
                printf(", ");
        }
        printf("]\n");
    }
}


int main(void)
{
    numlib_mat3x3f a = {{
        { 2, 3, 4 },
        { 2, 3, 4 },
        { 2, 3, 4 }
    }};
    
    numlib_mat3x3f b = { {
        { 2, 3, 4 },
        { 2, 3, 4 },
        { 2, 3, 4 }
    } };

    print_float_matrix(numlib_mat3x3f_mult(&a, &b).arr, 3, 3);

    return 0;
}