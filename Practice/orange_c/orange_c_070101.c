#include <stdio.h>

int main(void)
{
    int num=0;
    int n=0;

    printf("정수를 입력해주세요 : ");
    scanf("%d",&num);

    while (n<num)
    {
        printf("Hello World! \n");
        n++;
    }

    return 0;
}