#include <stdio.h>
#include "Heap.c"

int PriComp(int n1, int n2)
{
    return n2-n1;
    //return n1-n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    for(i=0;i<n;i++)
        HInsert(&heap,arr[i]);

    for(i=0;i<n;i++)
        arr[i]=HDelete(&heap);
}

int main(void)
{
    int arr[8]={8,1,3,5,2,4,9,11};
    int i;

    HeapSort(arr, sizeof(arr)/sizeof(int),PriComp);

    for(i=0;i<8;i++)
        printf("%d ",arr[i]);

    printf("\n");
    return 0;
}