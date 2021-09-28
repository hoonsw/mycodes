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
	
	scanf("%d",&numbers);
	
	elements = (int*)malloc(sizeof(int)*numbers);

    if(elements!=NULL) 
    {
        for(int i=0;i<numbers;i++)
        {
            scanf("%d",elements+i); // 여기서 왜 elements[i]로 하면 에러가?
        }
    }

    bubblesort(elements, numbers);

    for(int i=0;i<numbers;i++)
    {
        printf("%d\n",elements[i]);
    }
	
    free(elements);
	return 0;
}
