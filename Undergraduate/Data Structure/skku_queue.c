#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4

typedef struct 
{
    int key;
} element;

element queue[MAX_QUEUE_SIZE];

int rear=0; int front=0;

void addq(element item)
{
    if(front==rear)
    {
        if(queue[front+1].key!=NULL)
        {
            fprintf(stderr,"Queue is Full!\n");
            exit(-1);
        }
        else
            queue[rear]=item;
    }
    queue[rear]=item;
    rear=(rear+1)%MAX_QUEUE_SIZE;
}

element deleteq()
{
    if(front==rear)
    {   
        if(queue[rear+1].key==NULL)
        {
            fprintf(stderr,"Queue is Empty!\n");
            exit(-1);
        }
        else 
        {
            front = (front+1)%MAX_QUEUE_SIZE;
            return queue[front];
        }
    }
    front = (front+1)%MAX_QUEUE_SIZE;
    return queue[front];
}

int main(void)
{
    element e,f;

    e.key=5; addq(e);
    e.key=4; addq(e);
    f=deleteq();
    f=deleteq();
    for(int i=0;i<4;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
    printf("%d %d\n",front,rear);

    return 0;
}