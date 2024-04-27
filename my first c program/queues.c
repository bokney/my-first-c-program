
//  queues.c
//  my first c program
//  Created by Cris Jarvis on 21/04/2024.

//  queue - first in first out

#include <stdlib.h>
#include "queues.h"

queue *queueCreate(void) {
    queue *newQueue = (queue *) malloc(sizeof(queue));
    if (newQueue == NULL) {
        printf("error - failed to malloc new queue\n");
        exit(1);
    }
    return newQueue;
}

void queueDestroy(queue *target) {
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
}

void queuePush(queue *target, void *data) {
    
}

void *queuePop(queue *target) {
    void *data = NULL;
    
    return data;
}
