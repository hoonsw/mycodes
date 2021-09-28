#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _stack
{
	double arr[100];
	int top;
} Stack;

void StackInit(Stack * stck)
{
	stck->top=-1;
}

int StackEmpty(Stack * stck)
{
	if(stck->top==-1)
		return 1;
	else 
		return 0;
}

void Push(Stack * stck, double data)
{
	stck->top+=1;
	stck->arr[stck->top]=data;
}

double Pop(Stack * stck)
{
    int remove;

    if(StackEmpty(stck))
    {
        printf("Stack is now empty \n");
        exit(-1);
    }

    remove=stck->top;
    stck->top-=1;

    return stck->arr[remove];
}

double prefixCal(char input[])
{
    Stack stack;
    int inputlen = strlen(input);
    char element, op1, op2;

    StackInit(&stack);

    for(int i=inputlen-1;i>-1;i--)
    {
        element = input[i];
        
        if(isdigit(element))
        {
            printf("%f를 스택에 푸시합니다. \n",(double)(element-'0'));
            Push(&stack,element-'0');
        }
        else if(element==' ')
        {
            printf("띄어쓰기를 패스합니다 \n");
            continue;
        }
        else
        {
            op2=Pop(&stack);
            op1=Pop(&stack); 
            printf("%f와 %f의 연산 진행 \n",op1,op2);

            switch(element)
            {
                case '+':
                    Push(&stack,op1+op2);
                    break;
                case '-':
                    Push(&stack,op1-op2);
                    break;
                case '*':
                    Push(&stack,op1*op2);
                    break;
                case '/':
                    Push(&stack,op1/op2);
                    break;
            }
        }
    }    
    return Pop(&stack);
}

int main(void) 
{
	char input[100];
	scanf("%[^\n]",input);
	printf("Hello Goorm! Your input is %s \n",input);

    printf("연산 결과 : %.2f\n",prefixCal(input));
	return 0;
}
