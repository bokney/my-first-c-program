
//  queues.h
//  my first c program
//  04/05/2024

#ifndef queues_h
#define queues_h

#include <stdio.h>
#include "lists.h"

typedef struct listNode_ queue;

void queuePush(queue **target, void *data);
void *queuePop(queue **target);

void queueReverse(queue **target);

unsigned int queueLength(queue *target);

#endif /* queues_h */
