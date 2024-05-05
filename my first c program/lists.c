
//  lists.c
//  my first c program
//  Created by Cris Jarvis on 21/04/2024.

#include <stdlib.h>
#include "listNodeAccess.h"
#include "lists.h"
#include "buckets.h"

// // // // // // // // // // // // // // // //

bucket *listBucket = NULL;

// // // // // // // // // // // // // // // //

void *listNodeCreate(void) {
    listNode *newNode;
    newNode = (listNode *) malloc(sizeof(listNode));
    if (newNode == NULL) {
        printf("error - failed to malloc new listNode\n");
        exit(1);
    }
    return newNode;
}

void listNodeInit(void *target) {
    listNode *node = target;
    if (target != NULL) {
        node->data = NULL;
        node->next = NULL;
    } else {
        printf("error - tried to initialise a NULL listNode\n");
        exit(1);
    }
}

void listNodeDestroy(void *target) {
    listNode *node = target;
    if (node == NULL) {
        printf("error - tried to free NULL listNode\n");
        exit(1);
    }
    if (node->data != NULL) {
        printf("error - listNode data should be NULL before destroying\n");
        node->data = NULL;
    }
    free(node);
}

// // // // // // // // // // // // // // // //

listNode *listBucketDelve(void) {
    if (listBucket == NULL) {
        listBucket = bucketCreate();
        bucketSetRoutines(listBucket, listNodeCreate,
                          listNodeInit, listNodeDestroy);
    }
    return bucketRequest(listBucket);
}

void listPrepend(listNode **target, void *data) {
    listNode *newNode = listBucketDelve();
    newNode->data = data;
    newNode->next = *target;
    *target = newNode;
}

void listAppend(listNode **target, void *data) {
    listNode *newNode = listBucketDelve();
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
    listNode *newNode = listBucketDelve();
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
            bucketReturn(listBucket, remove);
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
        bucketReturn(listBucket, traversal);
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

void listBucketDestroy(void) {
    bucketDestroy(listBucket);
}

void quereyListBucket(void) {
    printf("Quereying listBucket:\n\t");
    bucketQuerey(listBucket);
}
