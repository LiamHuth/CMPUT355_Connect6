#include "utils.h"
#include <iostream>

char getInput() {
    // get single character from stdin
    char input;
    input = getchar();

    // clean input
    if (input <= 8) { return '~'; }
    if (input >= 11 && input <= 31) { return '~'; }

    // flush stdin for multi char inputs
    fflush(stdin);                                                              // in case input is larger than 8 bits
    return input;
}
