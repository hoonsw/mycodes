#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4

typedef struct 
{
    int key;
} element;

element queue[MAX_QUEUE_SIZE];

int rear=0; int front=0; int cnt=0; 

void addq(element item)
{
    if (front==rear&&cnt==MAX_QUEUE_SIZE)
    {
        fprintf(stderr,"Queue is Full!\n");
        exit(-1);
    }
    queue[rear]=item;
    rear=(rear+1)%MAX_QUEUE_SIZE;
    cnt++;
}

element deleteq()
{
    if(front==rear&&cnt==0)
    {   
        fprintf(stderr,"Queue is Empty!\n");
        exit(-1);
    }
    front = (front+1)%MAX_QUEUE_SIZE;
    cnt--;
    return queue[front];
}

int main(void)
{
    element e,f;

    e.key=5; addq(e);
    e.key=4; addq(e);
    e.key=3; addq(e);
    e.key=2; addq(e);
    e.key=1; addq(e);
    
    printf("\n");
    printf("%d %d %d\n",front,rear,cnt);

    return 0;
}