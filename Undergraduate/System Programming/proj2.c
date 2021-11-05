#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void pwdFunction()
{
    
}

/* based on basic shell e5*/
int main()
{
	char str[50]; // path
	char* cmd=NULL;
	size_t size=0;
    pid_t pid;
    char* arg[202]; // arg[0] : execute

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

        if(strcmp(arg[0],"quit")==0)
        {
            break;
        }
        pid=fork();
        
        if(pid==0) // child process 
        {
            if(execv(str,arg)==-1)
            {
                printf("execv error! \n");
                break;
            }
            else if(strcmp(arg[0]),"pwd")
            {
                pwdFunction();
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
