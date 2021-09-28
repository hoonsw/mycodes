#include <stdio.h>
#include "DLinkedList.h"
#include "DLinkedList.c"

int main(void)
{
    //리스트 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    LInsert(&list,11); LInsert(&list,11);
    LInsert(&list,33); LInsert(&list,33);
    LInsert(&list,55); 

    //저장된 데이터 전체 출력
    printf("현재 데이터의 수 : %d \n",LCount(&list));

    if(LFirst(&list,&data))
    {   
        printf("%d ",data);

        while(LNext(&list,&data))
            printf("%d ",data);
    }
    printf("\n\n");

    // 숫자 33 모두 삭제 
    if(LFirst(&list,&data))
    {
        if(data==33)
            LRemove(&list);

        while(LNext(&list,&data))
        {
            if(data==33)
                LRemove(&list);
        }
    }

    //삭제 후 데이터 출력
    printf("현재 데이터의 수 : %d \n",LCount(&list));

    if(LFirst(&list,&data))
    {
        printf("%d ",data);

        while(LNext(&list,&data))
            printf("%d ",data);
    }
    printf("\n\n");
    return 0;
}