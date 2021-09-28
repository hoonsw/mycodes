#include <stdio.h>

int main(void)
{
    int temp;
    int sum;

    while (temp!=0)
    {
        printf("정수 입력  : \n");
        scanf("%d",&temp);
        sum+=temp;
    }

    printf("합 : %d",sum);
    return 0;
}