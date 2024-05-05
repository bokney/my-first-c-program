
//  buckets.c
//  my first c program
//  30/04/2024

#include <stdlib.h>
#include "buckets.h"
#include "lists.h"

// // // // // // // // // // // // // // // //

struct bucket_ {
    listNode *list;
    void *(*create)(void);
    void (*init)(void *data);
    void (*destroy)(void *data);
};

// // // // // // // // // // // // // // // //

listNode *spare = NULL;

// // // // // // // // // // // // // // // //

void *bucketCreate(void) {
    bucket *newBucket;
    if (spare == NULL) {
        newBucket = (bucket *) malloc(sizeof(bucket));
        if (newBucket == NULL) {
            printf("error creating new bucket\n");
            exit(1);
        }
    } else {
        newBucket = listRemoveNode(&spare, 0);
    }
    bucketInit(newBucket);
    return newBucket;
}

void bucketInit(bucket *target) {
    target->list = NULL;
    target->create = NULL;
    target->init = NULL;
    target->destroy = NULL;
}

void bucketDestroy(bucket *target) {
    if (target == NULL) {
        printf("error - tried to destroy NULL bucket\n");
        exit(1);
    }
    int length = listLength(target->list);
    for (int i = 0; i < length; i++) {
        //target->destroy(target->list);
        // have a think
        //free(listRemoveNode(&target->list, 0));
    }
    // free(target);
    listPrepend(&spare, target);
}

// // // // // // // // // // // // // // // //

void bucketSetCreate(bucket *target, void *(*func)(void)) {
    if (target == NULL) {
        printf("error - tried to set create routine of a NULL bucket\n");
        exit(1);
    }
    target->create = func;
}

void bucketSetInit(bucket *target, void (*func)(void *data)) {
    if (target == NULL) {
        printf("error - tried to set init routine of a NULL bucket\n");
        exit(1);
    }
    target->init = func;
}

void bucketSetDestroy(bucket *target, void (*func)(void *data)) {
    if (target == NULL) {
        printf("error - tried to set destroy routine of a NULL bucket\n");
        exit(1);
    }
    target->destroy = func;
}

void bucketSetRoutines(bucket *target,
                       void *(*create)(void),
                       void (*init)(void *data),
                       void (*destroy)(void *data)) {
    if (target == NULL) {
        printf("error - tried to set routines of a NULL bucket\n");
        exit(1);
    }
    target->create = create;
    target->init = init;
    target->destroy = destroy;
}

// // // // // // // // // // // // // // // //

void *bucketRequest(bucket *target) {
    if (target == NULL) {
        printf("error - requested from NULL bucket\n");
        exit(1);
    }
    void *data = NULL;
    if (target->list == NULL) {
        data = target->create();
    } else {
        data = listRemoveNode(&target->list, 0);
    }
    target->init(data);
    return data;
}

void bucketReturn(bucket *target, void *data) {
    if (target == NULL) {
        printf("error - tried to return data to a NULL bucket\n");
        exit(1);
    } else if (data == NULL) {
        printf("error - tried to return NULL data to a bucket\n");
        exit(1);
    }
    listPrepend(&target->list, data);
}

// // // // // // // // // // // // // // // //

void bucketQuerey(bucket *target) {
    if (target == NULL) {
        printf("error - tried to querey a NULL bucket\n");
        exit(1);
    }
    printf("Bucket has %u instances stored\n", listLength(target->list));
}
