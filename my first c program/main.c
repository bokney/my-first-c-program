
//  main.c
//  my first c program
//  20/04/2024

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "buckets.h"

typedef struct blob_ {
    //char string[32];
    int number;
} blob;

void *blobCreate(void) {
    blob *newBlob = (blob *) malloc(sizeof(blob));
    return newBlob;
}

void blobInit(void *target) {
    blob *daBlob = target;
    //for (int i = 0; i < 32; i++) target->string[i] = 48 + i;
    daBlob->number = 0;
}

void blobDestroy(void *target) {
    blob *daBlob = target;
    if (daBlob == NULL) {
        printf("error - tried to destroy a NULL blob");
    }
    free(daBlob);
}

void printBlob(blob *target) {
    blob *daBlob = target;
    if (daBlob != NULL) {
        printf("blob has number: %i\n", daBlob->number);
    } else {
        
    }
}

void printList(listNode *list) {
    int length = listLength(list);
    for (int i = 0; i < length; i++) {
        printf("[%u] ", listRetrieve(list, i));
    }
    printf("\n");
}

void printListLength(listNode *list) {
    printf("list has length %u\n", listLength(list));
}

void printReportSpare(void) {
    //printf("there are currently %u spare nodes\n", listNodeCountSpare());
    quereyListBucket();
}

void printNewLine(void) {
    printf("\n");
}

int main(int argc, const char * argv[]) {

    listNode *theList = NULL;
    
    printListLength(theList);
        
    printf("Appending...\n");
    for (int i = 0; i < 3; i++) {
        listAppend(&theList, i);
        printList(theList);
    }
    printListLength(theList);
    printNewLine();
    
    printf("Prepending...\n");
    for (int i = 0; i < 3; i++) {
        listPrepend(&theList, i);
        printList(theList);
    }
    printListLength(theList);
    printNewLine();
    
    printReportSpare();
    
    printf("Removing...\n");
    int l = listLength(theList) - 2;
    for (int i = l; i > 0; i--) {
        
        int j = (int) listRemoveNode(&theList, i);
        printf("removed %i, data = %i\n", i, j);
        printList(theList);
    }

    printReportSpare();
    
    printf("Inserting...\n");
    for (int i = 0; i < 2; i++) {
        listInsert(&theList, 123, 1);
        printList(theList);
    }
    printListLength(theList);
    printNewLine();
    
    printReportSpare();

    printf("Removing...\n");
    //int l = listLength(theList) - 1;
    for (int i = 0; i  < 2; i++) {
        int j = (int) listRemoveNode(&theList, 1);
        printf("removed %i, data = %i\n", i, j);
        printList(theList);
    }
    
    printReportSpare();
    
    printf("Prepending...\n");
    for (int i = 0; i < 16; i++) {
        listPrepend(&theList, i);
        printList(theList);
    }
    printListLength(theList);
    printNewLine();
    
    printReportSpare();
    
    
    bucket *blobBucket = bucketCreate();
    bucketSetRoutines(blobBucket, blobCreate, blobInit, blobDestroy);
    printf("Quereying blobBucket:\n\t");
    bucketQuerey(blobBucket);
    
    blob *getOne = bucketRequest(blobBucket);
    
    
    //getOne->string = "hello there";
    getOne->number = 44;
    
    printBlob(getOne);
    bucketReturn(blobBucket, getOne);
    printf("Quereying blobBucket:\n\t");
    bucketQuerey(blobBucket);
    
    bucketDestroy(blobBucket);
    
    return 0;
}
