#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <fcntl.h>

#define COMMAND 200

int tokenizerFunc(char* cmd, char** tokens)
{
    int i=0;
    char* ptr = strtok(cmd," ");

    while(ptr!=NULL)
    {
        tokens[i++]=ptr;
        ptr=strtok(NULL, " ");
    }
	
    return i+1; // return numbers of words 
}

void redirectFunc1(char** tokens, int count)  // input redirection <
{
    int fd;
    pid_t pid;

    /* child process */
    if((pid==fork())==0)
    {
        if(fd=open(tokens[count+1],O_RDONLY)==-1)
        {
            fprintf(stdout,"%s\n",strerror(errno));
            exit(EXIT_FAILURE);
        }
        dup2(fd,0);
        close(fd);
    }
    else
        wait(NULL);
} 

void redirectFunc2(char** tokens, int count) // output redirection >
{
    int fd;
    pid_t pid;

    /* child process */
    if((pid==fork())==0)
    {
        if(fd=open(tokens[count+1],O_RDWR|O_CREAT)==-1)
        {
            fprintf(stdout,"%s\n",strerror(errno));
            exit(EXIT_FAILURE);
        }
        dup2(fd,1);
        close(fd);
    }
    else
        wait(NULL);

}

void redirectFunc3(char** tokens, int count) // output redirection (appending) >>
{
    int fd;
    pid_t pid;

    /* child process */
    if((pid==fork())==0)
    {
        if(fd=open(tokens[count+1],O_RDWR|O_APPEND)==-1)
        {
            fprintf(stdout,"%s\n",strerror(errno));
            exit(EXIT_FAILURE);
        }
        dup2(fd,1);
        close(fd);
    }
    else
        wait(NULL);

}

int main(void)
{
    char str[50];
    char cmd[COMMAND]; // command line string

    char* tokens[50]; // word tokens 
    

    while(1)
    {
        /* get command from stdin */
        getline(&cmd,&size,stdin);
		cmd[strlen(cmd)-1]='\0';
        
        int cnt = tokenizerFunc(cmd,tokens); // tokenize and get number of words 

        for(int i=0;i<cnt;i++)
        {
            if(strcmp(tokens[i],"<"))
            {
                int redirectCnt1=i;
                redirectFunc1(tokens,redirectCnt1);
            }
            else if(strcmp(tokens[i],">"))
            {
                int redirectCnt2=i;
                redirectFunc2(tokens,redirectCnt2);
            }
            else if(strcmp(tokens[i]),">>")
            {
                int redirectCnt3=i;
                redirectFunc3(tokens,redirectCnt3);
            }
            else if(strcmp(tokens[i],"|")) // not implemented 
            {
                continue;
            }
            else if(strcmp(tokens[i]),"exit")) // exit
            {
                if(atoi(tokens[i+1])>-1&&atoi(tokens[i+1])<150)
                {
                    errno=atoi(tokens[i+1]);
                    fprintf(stdout,"%s\n",strerror(errno));
                    exit(EXIT_FAILURE);
                }
            }
            else
            {

            }
        }
    }
}
