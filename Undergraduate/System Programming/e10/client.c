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
    int n, clientFd, fd;
    struct hostent* h;
    struct sockaddr_in serverAddr;
    char buf[FILESIZE];
    char* host = argv[1];
    int portNumber = atoi(argv[1]);
    char txt1[] = "File name : ";
    char fileName[FILENAME];

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


    // read() iteration
    while((n=read(0,buf,FILENAME))>0)
    {
        buf[n]='\0'; // null

        // print out "File name : @@@"
        write(1,txt1,sizeof(txt1)-1);
        write(1,buf,n);

        strncpy(fileName,buf,n); // store file name to fileName

        // send quit string and quit client 
        if(strcmp(fileName,"quit")==0)
        {
            send(clientFd,fileName,FILENAME,0);
            return 0;
        }

        // send file name
        if(send(clientFd,fileName,FILENAME,0)<0)
        {
            printf("file name send failure\n");
            exit(0);
        }

        // open file
        fd=open(fileName,O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if(fd<0)
        {
            printf("cannot open the file\n");
            exit(0);
        }

        // send file 
        while(fgets(buf,FILESIZE,fd)!=NULL) // set fd data to buf
        {
            if((send(clientFd,buf,FILESIZE,0))<0) // send buf data to clientFd
            {
                printf("file send fail\n");
                exit(0);
            }
        }

    }
    close(clientFd);
    close(fd);
    return 0;
}