#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* queue for FIFO WS algorithm */
typedef struct Node
{
    int data;
    struct Node * next;
}Node;

typedef struct Queue 
{
    Node * front;
    Node * rear;
    int numOfData;
}Queue;

void queueInit(Queue* q)
{
    q->front=NULL;
    q->rear=NULL;
    q->numOfData=0;
}

int queueAdd(Queue* q, int val) 
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->next=NULL;
    new->data=val;
    q->numOfData++;

    if(q->front==NULL&&q->rear==NULL)
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

int queueDel(Queue* q) 
{
    Node* del;
    int reData;

    if(q->front==NULL&&q->rear==NULL)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    
    del=q->front;
    reData=del->data;
    q->front=q->front->next;
    q->numOfData--;

    free(del);
    return reData;
}

void fifoFunc(int _pageFrame,int _refStringSize,int* _refString)
{
    int faultCnt=0;
    int i,j,k;
    int flag=0; // hit check
    FILE* fp3 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","a");
    fprintf(fp3,"FIFO====================\n");
    // create queue and init 
    Queue pFrame;
    queueInit(&pFrame);
    
    Node* search = pFrame.front; // for check hit
    Node* search2 = pFrame.front; // for print queue 

    for(i=0;i<_refStringSize;i++) // get refstring one by one 
    {
        while(search!=NULL)
        {
            if(search->data==_refString[i]) // hit
            {
                flag=1;
                while(search2!=NULL) // print memory state 
                {
                    fprintf(fp3,"%d ",search2->data);  
                    search2=search2->next;
                }
                fprintf(fp3,"\n");  
                break;
            }
            search=search->next;
        }

        /* init pointers */
        search=pFrame.front;
        search2 = pFrame.front;

        if(flag==1)
        {
            /* init values, pointers */
            flag=0;
            continue;
        }
        else if(flag==0) // miss 할 때 메모리 상태가 출력이 안 되는 문제를 고쳐야 함. 
        {
            faultCnt++; 
            if(pFrame.numOfData==_pageFrame) // queue is full 얘만 나옴......... if check 문제? add-del 순서로 하면 무한루프. del-add 순서로 하면 else if 진입불가  
            {
                queueDel(&pFrame);
                queueAdd(&pFrame,_refString[i]);
                while(search2!=NULL) // print memory state 
                {
                    fprintf(fp3,"%d ",search2->data);
                    //printf("%d*",search2->data);
                    search2=search2->next;
                }
                fprintf(fp3,"!! page fault !!\n");  
            }
            else if(pFrame.numOfData<_pageFrame && pFrame.numOfData>-1) // queue is not full 얘는 안나옴..........
            {
                queueAdd(&pFrame,_refString[i]);
                while(search2!=NULL) // print memory state 
                {
                    fprintf(fp3,"%d ",search2->data);  
                    //printf("%d^",search2->data);

                    search2=search2->next;
                }
                fprintf(fp3,"!! page fault !!\n"); 
            }
            /* init values, pointers */
            search=pFrame.front;
            search2 = pFrame.front;
        }
    }

    fprintf(fp3,"TOTAL PAGE FAULT : %d\n",faultCnt);

    fclose(fp3);
}

    int main(void)
{
    int page;
    int pageFrame; // not used in WS algorithm
    int windowSize; // only used in WS algorithm
    int refStringSize;
    int refString[1000];
    char buf[1024]; // buffer for input&output
    int i=0;

    FILE* fp = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\input.txt","r"); 

    fgets(buf,sizeof(buf),fp); // get first line of input.txt

    // assign variables 
    page=atoi(buf);
    pageFrame=atoi(buf+2);
    windowSize=atoi(buf+4);
    refStringSize=atoi(buf+6);

    // error handling (input)
    for(i=0;i<4;i++)
    {
        if(*(buf+2*i)<-1||*(buf+2*i)>1001)
            {
                printf("input error\n");
                exit(0);
            }
    }
    if((refStringSize-windowSize)<0)
    {
        printf("size of window is bigger than size of reference string\n");
        exit(0);
    }

    i=0;

    fgets(buf,sizeof(buf),fp); // get second line of input.txt
    // assign string to array 
    char* ptr=strtok(buf," ");
    while(ptr!=NULL)
    {
        refString[i]=atoi(ptr);
        i++;

        ptr = strtok(NULL, " ");
    }

    fclose(fp);

    FILE* fp2 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","w"); // make output.txt

    fifoFunc(pageFrame,refStringSize,refString);
    fclose(fp2);

    printf("complete\n");
    return 0;
}