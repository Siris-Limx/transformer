#include "common/softmax.h"
#include <stdint.h>
#include <stdio.h>

void softmax(int* input, int* output, int row, int col)
{
   for(int row_id = 0; row_id < row; row_id++)
   {
        int acc = 0;
        for(int col_id = 0; col_id < col; col_id++)
        {
            int index = row_id * col + col_id;
            output[index] = 1 << input[index];
            acc += output[index];
            output[index] <<= 7;
        }
        for(int col_id = 0; col_id < col; col_id++)
        {
            output[row_id * col + col_id] /= acc;
        }
   } 
}