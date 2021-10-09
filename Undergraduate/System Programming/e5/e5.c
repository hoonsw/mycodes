//#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char str[10]; // path
	char* cmd=NULL;
	size_t size=0;
    pid_t pid;
    char* arg[20]; // arg[0] : execute

	while(1)
	{
		getline(&cmd,&size,stdin);
		cmd[strlen(cmd)-1]='\0';
		int i=0;
		char* ptr = strtok(cmd," ");
		while(ptr!=NULL)
		{
			arg[i++]=ptr;
			ptr=strtok(NULL, " ");
		}
		arg[i]=NULL;
        sprintf(str,"/bin/%s",arg[0]);

        if(strncmp(arg[0],"quit",4)==0)
        {
            break;
        }
        pid=fork();
        
        if(pid==0)
        {
            if(execv(str,arg)==-1)
            {
                printf("execv error! \n");
                break;
            }
            else
                exit(0);
        }
        else
        {
        wait(NULL);
        }
	}
	
	return 0;	
}
