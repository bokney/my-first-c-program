
//  stacks.c
//  my first c program
//  Created by Cris Jarvis on 21/04/2024.

//  stack - last in first out

#include <stdlib.h>
#include "stacks.h"

stack *stackCreate(void) {
    return NULL;
}

void stackDestroy(stack *target) {
    /*
    if (target != NULL) {
        listNode *traversal = target->list;
        listNode *previous = traversal;
        while (traversal != NULL) {
            traversal = traversal->next;
            listNodeDestroy(previous);
            previous = traversal;
        }
    }
    free(target);
    */
}

void stackPush(stack *target, void *data) {
    listPrepend(&target, data);
}

void *stackPop(stack *target) {
    return listRemoveNode(&target, 0);
}
