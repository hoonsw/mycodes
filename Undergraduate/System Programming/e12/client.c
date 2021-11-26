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
#define USERNAME 200

int main(int argc, int **argv)
{
    int n, clientFd, r;
    struct hostent* h;
    struct sockaddr_in serverAddr;
    char buf[1024];
    char bufRecv[1024];
    char* host = argv[1];
    int portNumber = atoi(argv[1]);
    char txt1[] = "Insert your name : ";
    char userName[USERNAME];

    // create socket()
    if((clientFd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        printf("socket() failed\n");
        exit(0);
    }

    // get localhost struct 
    if((h=gethostbyname(host))==NULL)
    {
        printf("invalid hostname %s\n",host);
        exit(0);
    }

    // set serverAddr struct 
    memset((char*)&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family=AF_INET;
    memcpy((char*)&serverAddr.sin_addr.s_addr,(char*)h->h_addr,h->h_length);
    serverAddr.sin_port=htons(portNumber);
    
    // connect()
    if(connect(clientFd,(struct sockaddr*)&serverAddr,sizeof(serverAddr))<0)
    {
        printf("connect() failed\n");
        exit(0);
    }

    //get user name and store
    write(1,txt1,sizeof(txt1)-1);
    n=read(0,buf,USERNAME);
    buf[n]='\0'; // null
    strncpy(userName,buf,n);

    //send userName
    send(clientFd,userName,USERNAME,0);

    // read() iteration
    while((n=read(0,buf,1024))>0)
    {
        // send quit string and quit client 
        if(strcmp(buf,"quit")==0)
        {
            send(clientFd,buf,1024,0);
            return 0;
        }

        // send message 
        if(send(clientFd,buf,1024,0)<0)
        {
            printf("message send failure\n");
            exit(0);
        }

        // recveive message 
        r=recv(clientFd,bufRecv,1024,0);
        if(r<0)
        {
            printf("recv() file failed\n");
            exit(0);
        }
        printf("Delivered : %s\n",bufRecv);
    }
    close(clientFd);
    return 0;
}