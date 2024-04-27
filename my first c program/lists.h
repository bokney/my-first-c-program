
//  lists.h
//  my first c program
//  Created by Cris Jarvis on 21/04/2024.

#ifndef lists_h
#define lists_h

#include <stdio.h>

typedef struct listNode_ {
    void *data;
    struct listNode_ *next;
} listNode;

listNode *listNodeCreate(void);
void listNodeDestroy(listNode *target);

unsigned int listNodeCountSpare(void);
void listNodeDestroySpare(void);

void listPrepend(listNode **target, void *data);
void listAppend(listNode **target, void *data);

void listInsert(listNode **target, void *data, unsigned int position);
void *listRetrieve(listNode *target, unsigned int position);
void *listRemoveNode(listNode **target, unsigned int position);

unsigned int listLength(listNode *target);
void listReverse(listNode **target);

#endif /* lists_h */