#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/msg.h>
#include <unistd.h>
#include <time.h> 
#include <signal.h>
#include <sys/wait.h>

#define T_MSG 20 
#define MAX_LEN 512

struct msg {
    long msgtype; 
    int sender; 
    char text[MAX_LEN];
};

struct msg_rt {
    long msgtype; 
    char timestamp[MAX_LEN];
};

int main() {
    key_t key = ftok(".", 'a');
    int my_id, receiver_id, pid;

    printf("My id: "); 
    scanf("%d", &my_id);
    getchar();  
    printf("Receiver's id: ");
    scanf("%d", &receiver_id); 
    getchar();

    int qid = msgget(key, IPC_CREAT | 0x1FF); 

    if (qid < 0) {
	perror("msgget faild");
    }
    /* Please do not modify up to this point */

    msgctl(key, IPC_RMID, NULL); //initialize message queue

    char* line=NULL;
    size_t len=0;

    if ((pid = fork()) == 0) { // child process , receiver 
	while (1) {		
            struct msg buf;
            struct msg_rt read_time;

            // for time sending 
            read_time.msgtype=my_id;
            time_t t1;
            time(&t1);
            strcpy(read_time.timestamp,ctime(&t1));

            if(msgrcv(qid,(void*)&buf,sizeof(struct msg),my_id,IPC_NOWAIT)>0) // if got message
            {
                printf("RECEIVED : %s\n",buf.text); // print received text
                read_time.msgtype=receiver_id+T_MSG;
                if(msgsnd(qid,(void*)&read_time,sizeof(struct msg_rt),IPC_NOWAIT)==-1) // send awk message
                {
                    exit(0); // error 
                }
            }

            //msgctl(qid, IPC_RMID, NULL); // initialize message queue

            if(msgrcv(qid,(void*)&read_time,sizeof(struct msg_rt),my_id+T_MSG,IPC_NOWAIT)>0) // got awk
            {
                printf("ACK FROM %ld AT %s",buf.msgtype,read_time.timestamp);
            }

        }
    }
    else {
	while (1) { 
            struct msg buf2;
            struct msg_rt read_time2;
            buf2.msgtype=receiver_id; // set msgtype to send
            buf2.sender=my_id; // set sender_id to send
    
            getline(&line,&len,stdin);
            line[strlen(line)-1]='\0'; // get string from stdin

            strcpy(buf2.text,line); // structure txt set 

            if(msgsnd(qid,(void*)&buf2,sizeof(struct msg),IPC_NOWAIT)==-1) // send chat message 
            {
                exit(0); // error
            }  

            if(strcmp(line,"quit")==0) // quit command 
            {
                kill(pid,SIGKILL);
                printf("QUIT\n");
                break;
            }
	    }
    }	

    return 0;
}
