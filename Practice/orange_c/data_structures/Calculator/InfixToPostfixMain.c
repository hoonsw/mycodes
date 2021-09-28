#include <stdio.h>
#include "InfixToPostfix.h"
#include "InfixToPostfix.c"
#include "ListBaseStack.c"

int main(void)
{
    char exp1[]="1+2*3";
    char exp2[]="3+(4*5)/4";
    char exp3[]="(1+2)*4+5/(6+1*4)+3";

    ConvToRPNExp(exp1);
    ConvToRPNExp(exp2);
    ConvToRPNExp(exp3);

    printf("%s \n",exp1);
    printf("%s \n",exp2);
    printf("%s \n",exp3);
    return 0;
}