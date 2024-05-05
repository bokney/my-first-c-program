
//  listNodeAccess.h
//  my first c program
//  03/05/2024

#ifndef listNodeAccess_h
#define listNodeAccess_h

struct listNode_ {
    void *data;
    struct listNode_ *next;
};

void *listNodeCreate(void);
void listNodeInit(void *target);
void listNodeDestroy(void *target);

#endif /* listNodeAccess_h */
