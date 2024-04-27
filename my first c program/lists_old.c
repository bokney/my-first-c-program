
//  lists.c
//  my first c program
//  Created by Cris Jarvis on 20/04/2024.

#include <stdlib.h>
#include "lists.h"
/*
listNode *listNodeCreate(void) {
    listNode *newNode = (listNode *) malloc(sizeof(listNode));
    if (!newNode) {
        printf("failed to malloc new listNode\n");
        exit(1);
    }
    return newNode;
}

void listNodeDestroy(listNode *target) {
    if (target != NULL) free(target);
    target = NULL;
}

list *listCreate(void) {
    list *newList = (list *) malloc(sizeof(list));
    if (!newList) {
        printf("error creating new list\n");
        exit(1);
    }
    return newList;
}

void listInit(list *target) {
    target->head = NULL;
    target->tail = NULL;
    target->current = NULL;
}

void listDestroy(list *target) {
    // maybe because the lists are on stack
    // rather than on heap (ie malloc'd)
    // they do not get destroyed manually
}

void listPrepend(list *target, void *data) {
    listNode *newNode = listNodeCreate();
    if (target->head == NULL) {
        target->tail = newNode;
        newNode->next = NULL;
    } else newNode->next = target->head;
    target->head = newNode;
}

void listAppend(list *target, void *data) {
    listNode *newNode = listNodeCreate();
    newNode->data = data;
    newNode->next = NULL;
    if (target->head == NULL) target->head = newNode;
    else target->tail->next = newNode;
    target->tail = newNode;
}

void listDeleteNode(list *target, listNode *node) {
    if (node == target->head) {
        if (target->head->next == NULL) {
            target->head = NULL;
            target->tail = NULL;
        } else {
            target->head = target->head->next;
        }
    } else {
        listNode *traversal = target->head;
        while (traversal != NULL && traversal->next != node) {
            traversal = traversal->next;
        }
        if (traversal != NULL) {
            traversal->next = node->next;
        }
    }
    free(node);
}

unsigned int listCount(list *target) {
    listNode *traversal = target->head;
    unsigned int i = 0;
    while (traversal != NULL) {
        i++;
        traversal = traversal->next;
    }
    return i;
}
*/
