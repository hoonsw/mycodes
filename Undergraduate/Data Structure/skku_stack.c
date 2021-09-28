#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 100

typedef struct 
{
    int key;
} element;

element stack[MAX_STACK_SIZE];
element stack_reverse[MAX_STACK_SIZE];
int top =-1;
int topforR =-1; 

void stackFull()
{
    fprintf(stderr,"Stack is FULL!");
    exit(EXIT_FAILURE);
}

void push(element item)
{
    if(top>=MAX_STACK_SIZE-1)
    {
        stackFull();
        return;
    }
    stack[++top]=item;
}

void push_r(element item)
{
    if(top>=MAX_STACK_SIZE-1)
    {
        stackFull();
        return;
    }
    stack_reverse[++topforR]=item;
}

element pop()
{
    if(top==-1)
        fprintf(stderr,"Stack is Empty!");
    return stack[top--];
}

int main(void)
{
    element e,f;
    srand(time(NULL));

    for(int i=0; i<10;i++)
    {
        e.key=(rand()%100+1);
        push(e);
    }

    for(int i=0;i<10;i++)
    {
        push_r(pop());
    }

    for(int i=0;i<10;i++)
        printf("%d ",stack_reverse[i]);

    return 0;
}