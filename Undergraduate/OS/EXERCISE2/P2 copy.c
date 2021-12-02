#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 경로 긴거 다 input.txt, output.txt로 바꾸고 리눅스에서 잘 돌아가는지 확인*/

    /* queue for FIFO algorithm */
    typedef struct Node
    {
        int data;
        struct Node * next;
    }Node;

    typedef struct Queue 
    {
        Node * front;
        Node * rear;
    }Queue;

    void queueInit(Queue* q)
    {
        q->front=NULL;
        q->rear=NULL;
    }
    
    int queueAdd(Queue* q, int val) 
    {
        Node* new = (Node*)malloc(sizeof(Node));
        new->next=NULL;
        new->data=val;

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

        free(del);
        return reData;
    }

    int queueIsFull(int size, int* _queue,int _front, int _rear)
    {
        if((_rear+1)%size==_front)
            return 1; // queue is full 
        else 
            return 0;
    }

    /* double linked list for MIN,LRU algorithm */ // 원형 연결 리스트로 구현해야 할까...
    typedef struct dNode
    {
        int data;
        struct dNode* next;
        struct dNode* prev;
    }dNode;

    typedef struct dLinkedList
    {
        Node * head;
        Node * cur;
        Node * tail;
        int numOfData;
    }dLinkedList;

    void bubbleSort(int* array, int sizeOfArray)
    {
        int i,j,temp=0;

        for(i=0;i<sizeOfArray;i++)
        {
            for(j=0;j<sizeOfArray-i;j++)
            {
                if(array[j]>array[j+1])
                {
                    temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        }
        
    }

    void minFunc(int _pageFrame,int _refStringSize,int* _refString)
    {
        int faultCnt=0;
        FILE* fp3 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","a");
        fprintf(fp3,"not implemented\n");
        fclose(fp3);
    }

    void fifoFunc(int _pageFrame,int _refStringSize,int* _refString)
    {
        int faultCnt=0;
        int i;
        int temp; // store refstring no.
        int flag=0; // duplicate check
        FILE* fp3 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","a");

        int queue[_pageFrame+1]; // queue init with pageframe 
        for(i=0;i<_pageFrame+1;i++)
            queue[i]=-1; 

        int front, rear=0; // queue is empty now  

        for(i=0;i<_refStringSize;i++) // get refstring one by one  여기서 hit check 알고리즘이 뭔가 문제가 있긴 하다
        {
            for(int j=0;j<_pageFrame;j++)
            {
                if(queue[j]==_refString[i]) // hit check, front 에서 rear 까지 fprintf 할 방법을 찾자. 
                {
                    continue;
                }
            }
            if(queueIsFull(_pageFrame,queue,front,rear)==1) // if queue is full, check page fault 
            {

            }
            else if(queueIsFull(_pageFrame,queue,front,rear)==0) // if queue is not full, check duplicate
            {

            }
            else    
                printf("error in FIFO\n");
        }
 
        fclose(fp3);
    }

    void lruFunc(int _pageFrame,int _refStringSize,int* _refString)
    {
        int faultCnt=0;
        FILE* fp3 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","a");
        fprintf(fp3,"not implemented\n");
        fclose(fp3);
    }

    void lfuFunc(int _pageFrame,int _refStringSize,int* _refString)
    {
        int faultCnt=0;
        FILE* fp3 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","a");
        fprintf(fp3,"not implemented\n");
        fclose(fp3);
    }

    void wsFunc(int _page,int _windowSize,int _refStringSize,int* _refString)
    {
        int faultCnt=0;
        int i,j,k;
        int flag=0;

        FILE* fp3 = fopen("C:\\Users\\rhyth\\Desktop\\Github\\Undergraduate\\OS\\EXERCISE2\\output.txt","a");
            
        /* init pages */
        int Pages[_page];
        for(i=0;i<_page;i++)
            Pages[i]=-1;

        /* minus time handling*/
        while(i<_windowSize)
        {
            for(j=0;j<_page;j++)
            {
                if(Pages[j]==_refString[i]) // hit 
                {
                    flag=1; // hit flag
                    for(k=0;k<_page;k++)
                        fprintf(fp3,"%d ",Pages[k]);
                    fprintf(fp3,"\n");
                    break;
                }
            }

            if(flag==1)
            {
                i++;
                flag=0;
                continue;
            }
            else if(flag==0) // miss 
            {
                faultCnt++;
                Pages[i]=_refString[i];
                //bubbleSort(Pages,_page);
                for(k=0;k<_page;k++)
                    fprintf(fp3,"%d ",Pages[k]);
                fprintf(fp3,"!! page fault !!\n");
                fprintf(fp3,"\n");
                i++;
            }
        }

        flag=0;

        /* take ref string */
        for(i=_windowSize;i<_refStringSize;i++)
        {
            for(k=0;k<_page;k++)
            {
                if(Pages[k]==_refString[i]) // hit 
                {
                    flag=1;
                    // bubbleSort(Pages,_page); // ascending order and print 
                    for(j=0;j<_page;j++)
                        fprintf(fp3,"%d ",Pages[j]);
                    fprintf(fp3,"\n");
                    break;
                }

            }
            
            if(flag==1)
            {
                flag=0;
                continue;
            }
            else if(flag==0) // miss
            {
                faultCnt++;
                _refString[i-_windowSize] // 얘를 배열에서 뺴야됨, 배열이 가득 차 있으면 
            }
        }

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
    printf("first line : %s\n",buf);

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
    if((windowSize-refStringSize)<0)
    {
        printf("size of window is less than size of reference string\n");
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
    fclose(fp2);

    minFunc(pageFrame,refStringSize,refString);
    fifoFunc(pageFrame,refStringSize,refString);
    lruFunc(pageFrame,refStringSize,refString);
    lfuFunc(pageFrame,refStringSize,refString);
    wsFunc(page,windowSize,refStringSize,refString);

    return 0;
}