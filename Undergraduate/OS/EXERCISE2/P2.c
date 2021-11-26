#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int page;
    int pageFrame; // not used in WS algorithm
    int windowSize; // only used in WS algorithm
    int refStringSize;
    int refString[1000];
    char buf[1024]; // buffer for input&output
    int i=0;

    FILE* fp = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\input.txt","r"); // 다 끝나고 input.txt로 수정

    fgets(buf,sizeof(buf),fp); // get first line of input.txt
    printf("first line : %s\n",buf);

    // assign variables 
    page=atoi(buf);
    pageFrame=atoi(buf+2);
    windowSize=atoi(buf+4);
    refStringSize=atoi(buf+6);

    // error handling (input)
    for(i=0;i<4;i++)
    {
        if(*(buf+2*i)<-1&&*(buf+2*i)>1001)
            {
                printf("input error\n");
                exit(0);
            }
    }

    i=0;

    fgets(buf,sizeof(buf),fp); // get second line of input.txt
    // assign string to array 
    char* ptr=strtok(buf," ");
    while(ptr!=NULL)
    {
        refString[i]=atoi(ptr);
        i++;

        ptr = strtok(NULL, " ");
    }

    fclose(fp);




    // output.txt 구현
    return 0;
}