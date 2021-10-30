#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    int fd[2];
    int fd2[2];
    pipe(fd);
    pid_t pid;

    pid=fork(); // child process create

    if(pid==0) 
    {
        pipe(fd2);
        pid=fork();

        if(pid==0) // process 1 (parent)
        {
            close(fd2[0]); // close unused end 
            dup2(fd2[1],1);
            execlp("ls","ls","-l",NULL);
            perror("fork() 2-1");
        }
        else // process 2 (child)
        {
            wait(pid);
            close(fd2[1]);
            dup2(fd2[0],0);
            close(fd[0]);
            dup2(fd[1],1);
            execlp("grep","grep",argv[1],NULL);
            perror("fork() 2-2");
        }
    }
    else // process 3 (child)
    {
        wait(pid);
        close(fd[1]);
        dup2(fd[0],0);
        execlp("wc","wc",NULL);
        perror("fork() 1");
    }

    return 0;
}
