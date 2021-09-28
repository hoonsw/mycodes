#include <stdio.h>
#include <stdlib.h>

/* Base data structure */
typedef struct listNode* listPointer;
typedef struct listNode
{
    int data;
    listPointer link;
};

/*주어진 리스트를 카피하고 뒤집어서 반환*/

listPointer invertedCopyList(listPointer ptr)
{
    listPointer copy_ptr, middle, trail, copy_start;
    copy_ptr=(listPointer)malloc(sizeof(*ptr));

    copy_ptr->data=ptr->data;
    copy_start=copy_ptr;

    while(ptr->link)
    {
        copy_ptr->data=ptr->data;
        ptr=ptr->link;
        copy_ptr=copy_ptr->link;
    } // 복사 코드 

    copy_ptr=copy_start;

    middle=NULL;
    while(copy_ptr)
    {
        trail=middle;
        middle=copy_ptr;
        copy_ptr=copy_ptr->link;
        middle->link=trail;
    }

    return middle; // 뒤집어서 반환 코드 
    free(copy_ptr);
}

