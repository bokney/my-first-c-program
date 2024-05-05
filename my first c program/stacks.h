
//  stacks.h
//  my first c program
//  04/05/2024

#ifndef stacks_h
#define stacks_h

#include <stdio.h>
#include "lists.h"

typedef struct listNode_ stack;

void stackPush(stack **target, void *data);
void *stackPop(stack **target);

void stackReverse(stack **target);

unsigned int stackLength(stack *target);

#endif /* stacks_h */
