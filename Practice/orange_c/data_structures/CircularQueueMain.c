#include <stdio.h>
#include "CircularQueue.h"
#include "CircularQueue.c"

int main(void)
{
    //Queue생성 및 초기화
    Queue q;
    QueueInit(&q);

    // 데이터 넣기
    Enqueue(&q,1); Enqueue(&q,2);
    Enqueue(&q,3); Enqueue(&q,4);
    Enqueue(&q,5);

    // 데이터 꺼내기
    while(!QIsEmpty(&q))
        printf("%d ",Dequeue(&q));

    printf("\n");

    printf("front: %d, rear:%d \n",q.front,q.rear);
    
    for(int i=0;i<10;i++)
        printf("%d ",q.queArr[i]);

    return 0;
}