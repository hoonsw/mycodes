#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void sort(int [], int);

int main(void)
{
    int i,n;
    int list[MAX_SIZE];
    printf("생성할 배열 개수 입력 : ");
    scanf("%d",&n);

    if(n<1||n>MAX_SIZE)
    {
        fprintf(stderr,"부적절한 값 \n");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<n;i++)
    {
        list[n]=rand()%1000;
        printf("%d",list[n]);
    }

    sort(list,n);
    printf("\n Sorted array : \n");
    for(i=0;i<n;i++)
        printf("%d",list[i]);
    printf("\n");
}

void sort(int list[], int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(list[j]<list[min])
                min=j;
        SWAP(list[i],list[min],temp);
    }
}
