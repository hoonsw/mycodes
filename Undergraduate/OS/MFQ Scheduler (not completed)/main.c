#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS 100 // 프로세스 수의 한계는 100개

int CPU_time=0;

typedef struct Process
{
    int PID;
    int arr_time;
    int queue;
    int cycles;
    int burst[100];
    int isBurst; // check if now bursting
    int isEnd; // check if this process ends
} Process;

typedef struct Node // node of a queue
{
    Process *p;
    struct Node *next;
} Node;

typedef struct Queue // queue 
{
    Node *front;
    Node *rear;
} Queue;

void QueueInit(Queue *q) // queue initialization
{
    q->front=NULL;
    q->rear=NULL;
}

int IsEmpty(Queue *q) // check if queue is empty
{
    if(q->front==NULL)
        return 1;
    else
        return 0;
}

void Enqueue(Queue *q, Process *pro) // insert the data into queue
{
    Node* new=(Node*)malloc(sizeof(Node));
    new->next=NULL;
    new->p=pro;
    
    if(IsEmpty(q))
    {
        q->front=new;
        q->rear=new;
    }
    else
    {
        q->rear->next=new;
        q->rear=new;
    }
}

Process* Dequeue(Queue *q) // delete a data of queue and return it 
{
    Node* del;
    Process* delpro;
    
    if(IsEmpty(q))
    {
        printf("Queue is already empty \n");
        exit(0);
    }

    del=q->front;
    delpro=del->p;
    q->front=q->front->next;

    free(del);
    return delpro;
}

int Scheduler_FCFS(Process* process)
{
    Queue* fcfs; 
    QueueInit(fcfs);
    Enqueue(fcfs,process);
    while(IsEmpty(fcfs)==0)
    {
        Burst_FCFS(fcfs);
    }

    return 0; 
}

void Burst_FCFS(Queue* FCFS)
{
    FCFS->front->p->isBurst=1; // cpu burst start
    
    int j=0;
    while(j<100)
    {
        if((FCFS->front->p->burst[j]==0)&&(FCFS->front->p->burst[j+1]!=NULL))
            j+=2;
        else 
            break;
    } // check cpu burst

    for(int i=0;;i++)
    {
        FCFS->front->p->burst[j]--;
        CPU_time++;
        if(FCFS->front->p->burst[j]==0)
            break;
    } // do cpu burst 

    FCFS->front->p->isBurst=0;

    IO_QUEUE(Dequeue(FCFS));

}

int Scheduler_RR(Process* process, int t_quantum)
{
    int time_quantum=t_quantum;
    Queue* rr;
    QueueInit(rr);
    Enqueue(rr,process);

    return 0; 
}

void BURST_RR(Queue* rr, int t_quantum)
{
    rr->front->p->isBurst=1; // cpu burst start
    int time_quantum=t_quantum; // set the time slice    
    int j=0;

    while(j<100)
    {
        if((rr->front->p->burst[j]==0)&&(rr->front->p->burst[j+1]!=NULL))
            j+=2;
        else 
            break;
    } // check cpu burst

    for(int i=0;;i++)
    {
        if(time_quantum<0)
        {
            rr->front->p->isBurst=0;
            IO_QUEUE(rr->front->p);
            Dequeue(rr->front);
            break;
        } // preemption if time slice is lower than zero 
        rr->front->p->burst[j]--;
        CPU_time++;
        t_quantum--;
        if(rr->front->p->burst[j]==0)
            break;
    } // do cpu burst 

    rr->front->p->isBurst=0;


}

int Scheduler_MFQ(Process* process)
{
    switch(process->queue) // queue allocation belong to process queue value
    {
        case 0:
        Scheduler_RR(process, 1);
        break;
        case 1:
        Scheduler_RR(process, 2);
        case 2:
        Scheduler_RR(process, 4);
        break;
        case 3:
        Scheduler_FCFS(process);
        break;
        default:
        exit(0);
    }

    return 0; 
}

int IO_QUEUE(Process* process)
{
    Queue* io_burst;
    QueueInit(io_burst);
    Enqueue(io_burst,process);


}

Queue* Burst_IO(Queue* ioburst)
{
    int i=1;
    while(i<100)
    {
        if((ioburst->front->p->burst[i]==0)&&(ioburst->front->p->burst[i+1]!=NULL))
            i+=2;
        else 
            break;
    }
    
    for(int j=0;;j++)
    {
        ioburst->front->p->burst[i]--;
        if(ioburst->front->p->burst[i]==0)
            break;
    }
    
    return Dequeue(ioburst->front);
}


int main()
{
    int numberOfprocess;
    FILE *fp = fopen("input.txt","r"); 
    FILE *fp2 = fopen("output.txt","w"); 
    
    if(fp==NULL)
    {
        fprintf(fp2,"cannot open the input file \n");
        exit(0);
    }

    fscanf(fp,"%d",&numberOfprocess);

    if(numberOfprocess>100)
    {
        fprintf(fp2,"max of process numbers is 100 \n");
        exit(0);
    }

    Process Ps[numberOfprocess]; // make process structures 

    for(int i=0;i<numberOfprocess;i++) // initialization of processes 
    {
        fscanf(fp, "%d %d %d %d",&Ps[i].PID,&Ps[i].arr_time,&Ps[i].queue,&Ps[i].cycles);
        int numberOfburst = (Ps[i].cycles)*2-1;
        if(numberOfburst>100)
        {
            fprintf(fp2,"number of burst is more than 100 \n");
            exit(0);
        }
        int j=0;
        while(j<numberOfburst)
        {
            fscanf(fp,"%d",&Ps[i].burst[j]);
            j++;
        }
        Ps[i].isBurst=0; Ps[i].isEnd=0;
    }

    for(int i=0;i<numberOfprocess;i++)
        Scheduler_MFQ(&Ps[i]);

    fclose(fp);
    fclose(fp2);

    return 0;
}