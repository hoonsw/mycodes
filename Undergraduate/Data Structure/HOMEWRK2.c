#include <stdio.h>
#include <stdlib.h>

void bubblesort(int elements[],int num)
{
    int temp;

    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num-1;j++)
        {
            if(elements[j]>elements[j+1])
            {
                temp = elements[j];
                elements[j]=elements[j+1];
                elements[j+1]=temp;
            }
        }
    }
}

int main() 
{
	int numbers; 
	int *elements;
	
    printf("몇개의 정수 입력? ");
	scanf("%d",&numbers);
	
	elements = (int*)malloc(sizeof(int)*numbers);

    if(elements!=NULL) 
    {
        for(int i=0;i<numbers;i++)
        {
            printf("%d번째 정수 입력 : ",i+1);
            scanf("%d",elements+i);
        }
    }
    for(int j=0;j<numbers;j++)
        printf("elements[%d] = %d \n",j,elements[j]);

    //bubblesort(elements, numbers);

    /*for(int i=0;i<numbers;i++)
    {
        printf("%d\n",elements[i]);
    }*/
	
    free(elements);
	return 0;
}
