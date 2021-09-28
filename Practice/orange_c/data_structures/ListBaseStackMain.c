#include <stdio.h>
#include "ListBaseStack.h"
#include "ListBaseStack.c"

int main(void)
{
    //stack생성및초기화//
    Stack stck;
    StackInit(&stck);

    //데이터 넣기//
    SPush(&stck,1); SPush(&stck,2);
    SPush(&stck,3); SPush(&stck,4);
    SPush(&stck,5); SPush(&stck,6);

    //데이터 꺼내기//
    while(!SIsEmpty(&stck))
        printf("%d ",SPop(&stck));

    return 0;
}