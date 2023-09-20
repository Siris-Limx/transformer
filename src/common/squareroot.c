#include "common/squareroot.h"
#include <stdint.h>
#include <stdio.h>

int squareroot(int input) {
    if (input == 0 || input == 1) {
        return input;
    }

    int output = input;

    while (1) {
        int next_x = (output + input / output) / 2;

        if (next_x == output || next_x >= output) {
            break;
        }

        output = next_x;
    }

    return output;
}
