#include <stdio.h>
#include "PostCalculator.h"
#include "PostCalculator.c"
#include "ListBaseStack.h"
#include "ListBaseStack.c"

int main(void)
{
    char postExp1[]="42*8+";
    char postExp2[]="123+*4/";

    printf("%s = %d \n",postExp1,EvalRPNExp(postExp1));
    printf("%s = %d \n",postExp2,EvalRPNExp(postExp2));

    return 0;
}