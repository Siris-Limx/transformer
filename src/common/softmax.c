#include "common/softmax.h"
#include <stdint.h>
#include <stdio.h>

void softmax(int* input, int* output, int row, int col)
{
    int exp_lut[1<<16];

    for (int i = 0; i < (1<<32); i++) {
        exp_lut[i] = i + 1;
    }

    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += exp_lut[input[i * col + j]];
        }
        for (int j = 0; j < col; j++) {
            output[i * col + j] = exp_lut[input[i * col + j]] / sum;
        }
    }
}