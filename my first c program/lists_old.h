
//  lists.h
//  my first c program
//  Created by Cris Jarvis on 20/04/2024.

#ifndef lists_h
#define lists_h

#include <stdio.h>

typedef struct listNode_ {
    void *data;
    struct listNode_ *next;
} listNode;

typedef struct list_ {
    listNode *head;
    listNode *tail;
    listNode *current;
} list;

list *listCreate(void);
void listInit(list *target);
void listDestroy(list *target); // needs work

void listPrepend(list *target, void *data);
 void listAppend(list *target, void *data);
//void *listInsert(list *target, unsigned int position);
void listDeleteNode(list *target, listNode *node);

unsigned int listCount(list *target);
//void listReverse(list *target);


#endif /* lists_h */
