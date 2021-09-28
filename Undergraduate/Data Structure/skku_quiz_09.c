#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

void stringremove (char *s, int i, int j)
{
    char string[MAX_SIZE], *temp=string;
    memset(string,0,sizeof(string));

    if(i<0||j>strlen(s))
    {
        fprintf(stderr,"position is out of bound\n");
        exit(1);
    }
    if(!strlen(s)) return 0;
    else if (strlen(s))
    {
        strncpy(temp,s,i);
        strcat(temp,s+i+j);
        strcpy(s,temp);
    }

}

int main(void)
{
    char *test="APPLECOM";
    stringremove(test,2,3);
    printf(test);
    return 0;
}