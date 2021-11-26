#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define BUF 128 
#define FILENAME 50

int main(int argc, int **argv)
{
    int n, r, listenFd, connectFd, cAddrLen, fd;
    int cnt=0;
    int userCnt=0;
    struct sockaddr_in clientAddr, serverAddr;
    struct hostent* h;
    int portNumber = atoi(argv[1]);
    char buf[1024];
    char fileSize[10];
    char* username[10];

    // create socket
    if((listenFd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        printf("socket() failed\n");
        exit(1);
    }

    //set server socket struct
    memset((char*)&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serverAddr.sin_port=htons(portNumber);

    // bind()
    if(bind(listenFd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0)
    {
        printf("bind() failed\n");
        exit(1);
    }

    // listen()
    if(listen(listenFd,5)<0)
    {
        printf("listen() failed\n");
        exit(1);
    }

    fd_set readset, copyset;
    FD_ZERO(&readset);
    FD_SET(listenFd, &readset);
    int fdmax = listenFd, fdnum;
        
    // accept() in interation 
    while(1)
    {
        cAddrLen=sizeof(clientAddr);
        copyset = readset;
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        if ((fdnum = select(fdmax + 1, &copyset, NULL, NULL, &timeout)) < 0) 
        {
            printf("select() failed\n");
            exit(0);
        }

        if (fdnum == 0) 
        {
            printf("Time out\n");
            continue;
        }
        for (int i = 0; i < fdmax + 1; i++) 
        {
            if (FD_ISSET(i, &copyset)) 
            {
                if (i == listenFd) 
                {
                    if ((connectFd = accept(listenFd, (struct sockaddr *)&clientAddr,(socklen_t *)&cAddrLen)) < 0) // accept()
                    {
                        printf ("accept() failed.\n");
                        continue;
                    }
                    userCnt++;
                    //get username
                    n = read(i, username[i], 200);
                    printf("%s joined. %d current users.\n",username[i],userCnt);
                    FD_SET(connectFd, &readset);
                    if (fdmax < connectFd) fdmax = connectFd;
                }
                else 
                {
                    if ((n = read(i, buf, 1024)) > 0) 
                    {
                        printf ("got %d bytes from client.\n", n);
                        write(i, buf, n);
                        if(strcmp(buf,"quit")==0) // receive quit
                        {
                            userCnt--;
                            printf("%s leaved. %d current users.\n",username[i],userCnt);
                        }
                    }
                    else 
                    {
                        FD_CLR(i, &readset);
                        printf("connection terminated.\n");
                        close(i);
                    }
                }
            }
        }

    }

    close(connectFd);
    close(fd);
    sleep(1);

    return 0;
}