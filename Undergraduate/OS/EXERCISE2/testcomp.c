#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compFunc(int* pages, int* workingset, int sizeOfPages, int sizeOfWS) // compare Pages&WS, remove elements in Pages not in WS
{
    int i,j=0;
    int temp=-1;
    for(i=0;i<sizeOfPages;i++)
    {
        for(j=0;j<sizeOfWS;j++)
        {
            if((pages[i]==-1)||(pages[i]==workingset[j]))
                break;
        }
        if(j==sizeOfWS)
        {
            pages[i]=-1;
            temp=i;
        }
    } // 비교하는 반복문이 뭔가 잘못됨 

    if(sizeOfPages<sizeOfWS) // synchronize two arrays 
    {
        for(i=0;i<sizeOfPages;i++)
            pages[i]=workingset[i];
    }
    else
    {
        for(i=0;i<sizeOfWS;i++)
            pages[i]=workingset[i];
    }

    printf("temp : %d\n",temp);

    return temp;
}

int main(void)
{
    int a[5]={9,-1,-1,-1,-1};
    int b[8]={1,2,3,4,5,6,-1,-1};

    int c[8]={1,2,3,4,5,6,7,8};
    int d[5]={1,2,3,4,9};

    compFunc(a,b,5,8);
    compFunc(c,d,8,5);

    printf("a : ");
    for(int i=0;i<5;i++)
        printf("%d ",a[i]);
    printf("\n");
    printf("b : ");
    for(int i=0;i<8;i++)
        printf("%d ",b[i]);
    printf("\n");
    printf("c : ");
    for(int i=0;i<8;i++)
        printf("%d ",c[i]);
    printf("\n");
    printf("d : ");
    for(int i=0;i<5;i++)
        printf("%d ",d[i]);
    printf("\n");

    return 0; 

}