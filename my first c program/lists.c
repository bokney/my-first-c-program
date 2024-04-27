
//  lists.c
//  my first c program
//  Created by Cris Jarvis on 21/04/2024.

#include <stdlib.h>
#include "lists.h"

listNode *spare = NULL;

listNode *listNodeCreate(void) {
    listNode *newNode;
    if (spare != NULL) {
        newNode = spare;
        spare = spare->next;
        newNode->next = NULL;
    } else {
        newNode = (listNode *) malloc(sizeof(listNode));
        if (newNode == NULL) {
            printf("error - failed to malloc new listNode\n");
            exit(1);
        }
    }
    return newNode;
}

void listNodeDestroy(listNode *target) {
    if (target == NULL) {
        printf("error - tried to free NULL listNode\n");
        exit(1);
    }
    if (target->data != NULL) {
        printf("error - listNode data should be NULL before destroying\n");
        target->data = NULL;
    }
    target->next = spare;
    spare = target;
}

unsigned int listNodeCountSpare(void) {
    int i = 0;
    listNode *traversal = spare;
    while (traversal != NULL) {
        traversal = traversal->next;
        i++;
    }
    return i;
}

void listNodeDestroySpare(void) {
    listNode *traversal = spare;
    while (traversal != NULL) {
        traversal = spare->next;
        free(spare);
        spare = traversal;
    }
}

void listPrepend(listNode **target, void *data) {
    listNode *newNode = listNodeCreate();
    newNode->data = data;
    newNode->next = *target;
    *target = newNode;
}

void listAppend(listNode **target, void *data) {
    listNode *newNode = listNodeCreate();
    newNode->data = data;
    newNode->next = NULL;
    if (!*target) {
        *target = newNode;
    } else {
        listNode *traversal = *target;
        while (traversal->next) {
            traversal = traversal->next;
        }
        traversal->next = newNode;
    }
}

void listInsert(listNode **target, void *data, unsigned int position) {
    listNode *newNode = listNodeCreate();
    newNode->data = data;
    if (position == 0) {
        *target = newNode;
        newNode->next = *target;
    } else {
        listNode *traversal = *target;
        listNode *previous = traversal;
        for (int i = 0; i < position; i++) {
            if (traversal == NULL) {
                printf("tried to insert listNode oob\n");
                exit(1);
            }
            previous = traversal;
            traversal = traversal->next;
        }
        previous->next = newNode;
        newNode->next = traversal;
    }
}

void *listRetrieve(listNode *target, unsigned int position) {
    for (int i = 0; i < position; i++) {
        if (target == NULL) goto nope;
        target = target->next;
    }
    if (target == NULL) {
    nope:
        printf("tried to retrieve listNode oob\n");
        return NULL;
    }
    return target->data;
}

void *listRemoveNode(listNode **target, unsigned int position) {
    void *data = NULL;
    if (position == 0) {
        if (*target != NULL) {
            listNode *remove = *target;
            *target = remove->next;
            data = remove->data;
            remove->data = NULL;
            listNodeDestroy(remove);
        } else goto nope;
    } else {
        listNode *traversal = *target;
        listNode *previous = traversal;
        for (int i = 0; i < position; i++) {
            if (traversal == NULL) goto nope;
            previous = traversal;
            traversal = traversal->next;
        }
        if (traversal == NULL) {
        nope:
            printf("tried to remove listNode oob\n");
            exit(1);
        }
        previous->next = traversal->next;
        data = traversal->data;
        traversal->data = NULL;
        listNodeDestroy(traversal);
    }
    return data;
}

unsigned int listLength(listNode *target) {
    unsigned int i = 0;
    while (target != NULL) {
        i++;
        target = target->next;
    }
    return i;
}

void listReverse(listNode **target) {
    listNode *previous = NULL;
    listNode *current = *target;
    listNode *next;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *target = previous;
}
