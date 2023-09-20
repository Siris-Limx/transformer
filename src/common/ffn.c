#include "common/ffn.h"
#include "common/matmul.h"
#include "common/relu.h"
#include <stdint.h>
#include <stdio.h>

void ffn(int *input, int *output, int input_dim, int hidden_dim, int output_dim, int *trans_1, int *trans_2)
{
    int *inner_result;
    matmul(input, trans_1, inner_result, 1, input_dim, hidden_dim);
    relu(inner_result, hidden_dim);
    matmul(inner_result, trans_2, output, 1, hidden_dim, output_dim);
}//ffn in Transformer consists of 1.linear transform 2.ReLU 3.linear transform