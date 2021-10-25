#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int count=0;
int N=0;

void handler(int sig)
{
	if(sig==SIGINT&&(N!=count))
	{
		count++;
	}
	else if(sig==SIGINT&&N==count)
	{
		signal(SIGINT,SIG_DFL);
		exit(1);
	}
	else if(sig==SIGQUIT)
	{
		printf("SIGQUIT caught, will be ignored\n");
	}
	else if(sig==SIGTSTP)
	{
		printf("SIGTSTP caught. This process will stop\n");
		//signal(SIGTSTP,SIG_DFL);
		kill(0,SIGSTOP);
	}
	else if(sig==SIGCONT)
	{
		printf("SIGCONT caught\n");
		signal(SIGCONT,SIG_DFL);
	}
	else
	{
		printf("There is some error\n");
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	N=atoi(argv[1]);

	signal(SIGINT,handler);
	signal(SIGQUIT,handler);
	signal(SIGTSTP,handler);
	signal(SIGCONT,handler);	

	while(1){}

	return 0;
}