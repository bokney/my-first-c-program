
//  stacks.c
//  my first c program
//  04/05/2024

//  stack - last in first out

#include <stdlib.h>
#include "stacks.h"

void stackPush(stack **target, void *data) {
    listAppend(target, data);
}

void *stackPop(stack **target) {
    return listRemoveNode(target, 0);
}

void stackReverse(stack **target) {
    listReverse(target);
}

unsigned int stackLength(stack *target) {
    return listLength(target);
}
