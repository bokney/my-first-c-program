
//  stacks.h
//  my first c program
//  Created by Cris Jarvis on 21/04/2024.

#ifndef stacks_h
#define stacks_h

#include <stdio.h>
#include "lists.h"

typedef struct listNode_ stack;

/*typedef struct stack_ {
    listNode *list;
} stack;
*/
stack *stackCreate(void);
void stackDestroy(stack *target);

void stackPush(stack *target, void *data);
void *stackPop(stack *target);

#endif /* stacks_h */
