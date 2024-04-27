
//  main.c
//  my first c program
//  Created by Cris Jarvis on 20/04/2024.

#include <stdio.h>
#include "lists.h"

void printList(listNode *list) {
    while (list) {
        printf("[%u] ", (int) list->data);
        list = list->next;
    }
    printf("\n");
}

void printListLength(listNode *list) {
    printf("list has length %u\n", listLength(list));
}

void printReportSpare() {
    printf("there are currently %u spare nodes\n", listNodeCountSpare());
}

void printNewLine() {
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
    
    return 0;
}
