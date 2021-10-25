#include <unistd.h>
#include <stdlib.h> // exit
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // open, close
#define NULL ((void *)0)

#include <stdio.h> // 테스트용삭제

char printOut[]="Enter Keyword(s) : ";

char error1[]="file open error\n";
char error2[]="reading error\n";
char error3[]="unvalid keyword input\n";

char test1[]="undefined searchcase\n";

char* myStrncpy(char* str1, char* str2, int len)
{
    char* result = str1;
    int i=0;
    
    while(i<len)
    {
        str1[i]=str2[i];
        i++;
    }
    
    return result;
}

int myStrncmp(char* str1, char* str2, int len)
{
    int i=0;
    while(i<len)
    {
        if(str1[i]==str2[i])
        {
            i++;
            continue;
        }
        else
            return 0;
    }
    return 1;
}

int myStrlen(char* str)
{
    int i=0;

    while(str[i]!='\0')
        i++;
    
    return i;
}

int* myStrstr(char* str1, char* str2) // strings, keywords
{
    int same=0;
    int numOfSpaces=0;
    int numOfEnters=0;
    int i=0;
    static int detector[400]={-1,};

    if(*str2=='\0')
        return NULL; 
    else
    {
        while(*str1!='\0')
        {
            if(*str1==' ')
                numOfSpaces++;

            if(*str1=='\n')
            {
                numOfEnters++;
                numOfSpaces=0;
            }

            if(*str1==*str2)
            {
                for(same=1;*(str1+same)==*(str2+same);same++);

                if(same==myStrlen(str2))
                {
                    detector[i]=numOfEnters+1;
                    detector[i+1]=numOfSpaces+1;
                    i+=2;
                }
           }
            str1++;
        }
    }
    
    printf("myststr call \n"); // 테스트
    return detector;
}

char* myStrtok(char* string)
{
    char* cleanString;
    int i=0;

    while(*string!='/0')
    {
        *(cleanString+i)=*(string+i);
        i++;    
    }

    cleanString[i]='\0';

    return cleanString;
}

/*int myGetline(char* buffer, char** txt, int len)
{
    char* startOfLine;
    startOfLine=buffer; // initialization 
    int line=0;

    char* txt[0]=startOfLine;

    for(int i=0;i<len+1;i++) // len+1 for '\0'
    {
        if(buffer[i]=='\n') // check end of the line 
        {
            char* txt[line]=startOfLine;
            startOfLine=&(buffer[i+1]);
            line++;
        }
        if(buffer[i]=='\0') // check end of the file 
        {
            char* txt[line]=startOfLine;
            break;
        }
    }

    return line; // number of line = line+1 (because line value is from 0)
}*/

void searchCaseOne(char* keyword, char* txt)
{
    int *list;
    list=myStrstr(txt,keyword);

    printf("list[0] : %d\n",list[0]);
    printf("list[1] : %d\n",list[1]);
    printf("list[2] : %d\n",list[2]);
    printf("list[3] : %d\n",list[3]);

    for(int i=0;list[i]>0;i++)//테스트존
        printf("%d ",list[i]);

    printf("\n\n\n");

    char buffer[8192];
    char testx[]="\nwhy dont you come out?";

    for(int i=0;list[i]>0;i++)
    {
        buffer[4*i]=list[2*i]+'0';
        buffer[4*i+1]=':';
        buffer[4*i+2]=list[2*i+1]+'0';
        buffer[4*i+3]='\n';
    }

        printf("%s",buffer); // 테스트용
    
    printf("\n\n\n\n"); // 테스트용 

    write(1,buffer,sizeof(buffer));
}

void searchCaseTwo(char* keyword, char* txt)
{
    write(1,test1,sizeof(test1)-1);
}

void searchCaseThree(char* keyword, char* txt)
{
    write(1,test1,sizeof(test1)-1);
}

void searchCaseFour(char* keyword, char* txt)
{
    write(1,test1,sizeof(test1)-1);
}

int main(int argc, char* argv[])
{
    int numOfWords;
    int fd; 
    char buf[8192]; // max buffer 8kb
    int readBytes=0;
    int readBytes2=0;
    char txtfile[8192]; // 8kb for input txt file strings 
    int lines;

    int spaceCount=0;
    int quotesCount=0;
    int asteriskCount=0;

    char* searchString[10]; // target string array into words 

    if((fd=open(argv[1],O_RDONLY))==-1) // input file open 
    {
        write(1,error1,sizeof(error1)-1); // if file not opened, print out error message
        exit(0);
    }

    /*readBytes=read(fd,buf,sizeof(buf));
    lines=myGetline(buf,txtfile,readBytes); // line by line to char** txtfiles

    buf={'\0',}; // initialize buffer*/

    write(1,printOut,sizeof(printOut)-1); // Enter Keyword(s) : 

    readBytes=read(0,buf,sizeof(buf)-1); // read keyword from stdin
    
    if(readBytes==-1) // check 
    {
        write(1,error2,sizeof(error2)-1); // if file not opened, print out error message
        exit(0);
    }

    buf[readBytes]='\0';

    readBytes2=read(fd,txtfile,sizeof(txtfile)-1);

    if(readBytes2==-1)
    {
        write(1,error2,sizeof(error2)-1); // if file not opened, print out error message
        exit(0);
    }

    txtfile[readBytes2]='\0';

    for(int i=0;i<readBytes;i++) // store numbers of the spaces/quotes/asterisks to Count values
    {
        if(buf[i]==' ')
            spaceCount++;
        
        if(buf[i]=='\"')
            quotesCount++;

        if(buf[i]=='*')
            asteriskCount++;
    }

    if(spaceCount==0)
        searchCaseOne(buf,txtfile);
    else if(spaceCount>0)
    {
        if(quotesCount==0&&asteriskCount==0)
            searchCaseTwo(buf,txtfile);
        else if(quotesCount==2&&asteriskCount==0)
            searchCaseThree(buf,txtfile);
        else if(quotesCount==0&&asteriskCount==1)
            searchCaseFour(buf,txtfile);
        else 
            write(1,error3,sizeof(error3)-1); // unvalid keyword input
    }
    else
        write(1,error3,sizeof(error3)-1);


    
    // 찾을 문자열, 공백으로 case 판단 -> strtok, strncpy, strncmp, strstr 구현
    // case1 공백 없는 한 단어일 때
    // case2 공백 있는 여러 단어일 때... 공백 수로 글자 수 추산, 반복문 돌리기?
    // case3 " 로 시작해 " 로 끝나는 문자열과 맞는 문자열들을 찾을 때
    // case4 word * word 형태 문자열에 맞는 모든 문자열들을 찾을 때

    /*
    "search "
    "search/n"

    strstr 포인터 대신 띄어쓰기 개수 반환
    포인터 훑을때 \n 검사후 카운트?

    1. strstr
    2. 같은 \n 카운트 내에 둘다 있으면 디텍트? 
    3. 1의 확장 
    4.
    2의확장
    같은 \n 카운트 내에서 
    first  last 사이에 띄어쓰기 두번만 있어야 함 
    strstr(last ) - strstr(first ) == 2 ??
    */
    close(fd);   
    return 0;
}
