#include "common/matmul.h"

// 定义矩阵乘法函数
void matmul(const int* matrix_a, const int* matrix_b,
                          int* result, int row_a, int col_a, int col_b)
{
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < col_b; j++) {
            int sum = 0;
            for (int k = 0; k < col_a; k++) {
                sum += matrix_a[i * col_a + k] * matrix_b[k * col_b + j];
            }
            result[i * col_b + j] = sum;
        }
    }
}