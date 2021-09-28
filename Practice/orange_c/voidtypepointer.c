#include <stdio.h>

void SoSimpleFunc(void)
{
    printf("I'm So Simple");
}

int main(void)
{
    int num=20;
    void* ptr;

    ptr=&num;
    printf("%p \n",ptr);

    ptr=SoSimpleFunc;
    printf("%p \n",ptr);
    return 0;
}