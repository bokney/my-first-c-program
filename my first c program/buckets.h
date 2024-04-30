
//  buckets.h
//  my first c program
//  30/04/2024

#ifndef buckets_h
#define buckets_h

#include <stdio.h>

typedef struct bucket_ bucket;

bucket *bucketCreate(void);
void bucketInit(bucket *target);
void bucketDestroy(bucket *target);

void bucketSetCreate(bucket *target, void *(*func)(void));
void bucketSetInit(bucket *target, void (*func)(void *data));
void bucketSetDestroy(bucket *target, void (*func)(void *data));
void bucketSetRoutines(bucket *target,
                       void *(*create)(void),
                       void (*init)(void *data),
                       void (*destroy)(void *data));

void *bucketRequest(bucket *target);
void bucketReturn(bucket *target, void *data);

#endif /* buckets_h */
