#include "common/transpose.h"

void transpose(int* input, int* output, int row, int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            output[j * row + i] = input[i * col + j];
        }
    }
}