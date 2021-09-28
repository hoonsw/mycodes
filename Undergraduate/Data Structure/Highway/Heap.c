#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HeapData;
typedef int PriorityCompare(HeapData d1, HeapData d2);

typedef struct _heap
{
    PriorityCompare * compare;
    int numofdata;
    HeapData heapArr[100];
} Heap;

void HeapInit(Heap* ph, PriorityCompare pc)
{
    ph->numofdata=0;
    ph->compare=pc; 
}
int HeapEmpty(Heap* ph);

void HeapInsert(Heap* ph, HeapData data);
HeapData HeapDelete(Heap* ph);

