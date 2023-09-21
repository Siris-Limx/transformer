#include "common/relu.h"
#include <stdint.h>
#include <stdio.h>

void relu(int* input, int dim)
{
    for(int id = 0; id < dim; id++)
        input[id] = max(0, input[id]);
}