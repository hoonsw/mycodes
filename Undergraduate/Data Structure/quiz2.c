#include <stdio.h>

int main(void)
{
    int arr[3]={-4,6,10};
    int temp;
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<3;i++)
        printf("%d ",arr[i]);
    
    return 0;
}