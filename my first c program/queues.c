
//  queues.c
//  my first c program
//  04/05/2024

//  queue - first in first out

#include <stdlib.h>
#include "queues.h"

void queuePush(queue **target, void *data) {
    listAppend(target, data);
}

void *queuePop(queue **target) {
    return listRemoveNode(target, 0);
}

void queueReverse(queue **target) {
    listReverse(target);
}

unsigned int queueLength(queue *target) {
    return listLength(target);
}
