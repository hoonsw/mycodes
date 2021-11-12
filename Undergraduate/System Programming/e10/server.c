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
#define FILESIZE 200100

int main(int argc, int **argv)
{
    int n, r, listenFd, connectFd, cAddrLen, fd;
    int cnt=0;
    struct sockaddr_in clientAddr, serverAddr;
    struct hostent* h;
    int portNumber = atoi(argv[1]);
    char buf[FILESIZE];
    char copyTxt[]="_copy";
    char fileSize[10];

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

    // accept() in interation 
    while(1)
    {
        cAddrLen=sizeof(clientAddr);
        if((connectFd=accept(listenFd,(struct sockaddr*)&clientAddr,(socklen_t *)&cAddrLen))<0)
        {
            printf("accept() failed\n");
            break;
        }
        
        // receive filename 
        char fileName[FILENAME+6];
        if(n=recv(connectFd,fileName,FILENAME,0)<0)
        {
            printf("recv() filename failed\n");
            break;
        }
        fileName[n]='\0'; // NULL

        // check if quit 
        if(strcmp(fileName,"quit"))
        {
            break;
        }

        strcpy(fileName,copyTxt); // append "_copy" and save 

        fd=open(fileName,O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // file open 
        if(fd==-1) //error handling
        {
            printf("file descriptor error\n");
            break;
        }

        // recv from socket and write to the file
        do
        {
            r=recv(connectFd,buf,FILESIZE,0);
            if(r<0)
            {
                printf("recv() file failed\n");
                exit(0);
            }
            if(write(fd,buf,r)<0)
            {
                printf("write() file failed\n");
                exit(0);
            }
            cnt+=r;
        } while (r>0);

        printf("got %d bytes from client.\n",cnt);
    }


    printf("connection terminated\n");
    close(connectFd);
    close(fd);
    sleep(1);

    return 0;
}