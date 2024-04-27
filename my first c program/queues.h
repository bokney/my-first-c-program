
//  queues.h
//  my first c program
//  Created by Cris Jarvis on 21/04/2024.

#ifndef queues_h
#define queues_h

#include <stdio.h>
#include "lists.h"

typedef struct queue_ {
    listNode *list;
} queue;

queue *queueCreate(void);
void queueDestroy(queue *target);

void queuePush(queue *target, void *data);
void *queuePop(queue *target);

#endif /* queues_h */
