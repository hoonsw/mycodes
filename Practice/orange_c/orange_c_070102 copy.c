#include <stdio.h>

int main(void)
{
    int temp;
    int sum=0;

    while (temp!=0)
    {
        printf("정수 입력  : ");
        scanf("%d",&temp);
        sum+=temp;
    }

    printf("합 : %d",sum);
    return 0;
}