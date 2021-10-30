#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
        unsigned int pid;
        time_t t;
        struct tm *tm;
        int fd;
        char *argv[3];
        char buf[512];
        int fd0, fd1, fd2;

        fd = open("./crontab", O_RDWR);
        pid = fork();

        if(pid == -1) return -1;
        if(pid != 0)
                exit(0);
        if(setsid() < 0)
                exit(0);
        if(chdir("/") < 0)
                exit(0);

        umask(0);

        close(0);
        close(1);
        close(2);

        fd0=open("/dev/null",O_RDWR);
        fd1=open("/dev/null",O_RDWR);
        fd2=open("/dev/null",O_RDWR);

        t = time(NULL);
        tm = localtime(&t);

        while(1)
        {
            buf[0]='\0';
            char *buf2 = buf; 

            if((pid=fork())!=0) // ?
            {
                int readFd;
                readFd=read(fd,buf,sizeof(buf));

                if(readFd==-1) // reading error handling 
                    exit(0);

                for(int i=0;i<3;i++) // crontab to **argv
                    argv[i]=strtok_r(buf2," ",&buf2);

                if(argv[0]!="*"&&argv[1]!="*") // minute, hour
                {
                    if((tm->tm_min==atoi(argv[0]))&&(tm->tm_hour==atoi(argv[1])))
                        execl("/bin/sh","/bin/sh","-c",argv[2],(char*)NULL);
                }
                else if(argv[0]=="*"&&argv[1]!="*") // every minute, specific hour
                {
                    if(tm->tm_hour==atoi(argv[1]))
                    {
                        execl("/bin/sh","/bin/sh","-c",argv[2],(char*)NULL);
                        sleep(60-tm->tm_sec%60);
                    }
                }
                else if(argv[0]!="*"&&argv[1]=="*") // specific minute, every hour
                {
                    if(tm->tm_min==atoi(argv[0]))
                        execl("/bin/sh","/bin/sh","-c",argv[2],(char*)NULL);
                }
                else if(argv[0]=="*"&&argv[1]=="*") // every minute, every hour
                {
                    execl("/bin/sh","/bin/sh","-c",argv[2],(char*)NULL);
                    sleep(60-tm->tm_sec%60);
                }
            }
            exit(0);

            /* hints
            pid=fork()
            execl("/bin/sh","/bin/sh","-c",argv[2],(char*)NULL)
            */

            t = time(NULL);
            tm = localtime(&t);

            sleep(60-tm->tm_sec%60);

        }

        return 0;
}