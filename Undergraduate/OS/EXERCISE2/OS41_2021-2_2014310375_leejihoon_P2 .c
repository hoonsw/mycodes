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

/* double linked list for MIN,LRU algorithm */ // 원형 연결 리스트로 구현해야 할까...
typedef struct dNode
{
    int data;
    struct dNode* next;
    struct dNode* prev;
}dNode;

typedef struct dLinkedList
{
    dNode * head;
    dNode * cur;
    dNode * tail;
    int numOfData;
}dLinkedList;

void listInit(dLinkedList* list)
{
    list->head=(dNode*)malloc(sizeof(dNode));
    list->tail=(dNode*)malloc(sizeof(dNode));

    list->head->prev=NULL;
    list->head->next=list->tail;

    list->tail->next=NULL;
    list->tail->prev=list->head;

    list->numOfData=0;
}

void listInsert(dLinkedList* list, int val)
{
    dNode* new = (dNode*)malloc(sizeof(dNode));
    new->data=val;

    new->prev=list->tail->prev;
    list->tail->prev->next=new;

    new->next=list->tail;
    list->tail->prev=new;

    (list->numOfData)++;
}

void listRemove(dLinkedList* list)
{
    dNode * pos = list->cur;

    list->cur->prev->next=list->cur->next;
    list->cur->next->prev=list->cur->prev;

    list->cur=list->cur->prev;

    free(pos);
    (list->numOfData)--;
}

/* tools for WS */

void bubbleSort(int* array, int sizeOfArray)
{

    int i,j,k,temp=0;
    int* tempArray = malloc(sizeof(int)*sizeOfArray);
    int tempArr[sizeOfArray];
    // make ascending order
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

    temp=sizeOfArray;
    // remove duplicate 
    for(i=0;i<sizeOfArray;i++)
    {
        for(j=i+1;j<sizeOfArray;j++)
        {
            if(array[i]==array[j])
            {
                for(k=j;k<sizeOfArray-1;k++)
                {
                    array[k]=array[k+1];
                }
                j--;
                sizeOfArray--;
            }
        }
    }

    for(i=sizeOfArray;i<temp;i++)
        array[i]=-1;
}

int compFunc(int* pages, int* workingset, int sizeOfPages, int sizeOfWS) // compare Pages&WS, remove elements in Pages not in WS
{
    int i,j=0;
    int temp=-1;
    int ret=-1;
    for(i=0;i<sizeOfPages;i++)
    {
        for(j=0;j<sizeOfWS;j++)
        {
            if((pages[i]==-1)||(pages[i]==workingset[j]))
                break;
        }
        if(j==sizeOfWS)
        {
            pages[i]=-1;
            temp=i;
        }
    }
    
    if(temp!=-1)
        ret=pages[temp];

    if(sizeOfPages<sizeOfWS) // synchronize two arrays 
    {
        for(i=0;i<sizeOfPages;i++)
            pages[i]=workingset[i];
    }
    else
    {
        for(i=0;i<sizeOfWS;i++)
            pages[i]=workingset[i];
    }

    return ret;
}

void minFunc(int _pageFrame,int _refStringSize,int* _refString)
{
    int faultCnt=0;
    int i,j,k=0;
    int flag,flag2,flag3=0;
    int far;
    int cnt=0;
    int idx;
    /*page frame init*/
    int pFrame[_pageFrame];
    for(i=0;i<_pageFrame;i++)
        pFrame[i]=-1;

    FILE* fp3 = fopen("output.txt","a");
    fprintf(fp3,"\n\nMIN====================\n");

    for(i=0;i<_refStringSize;i++) // get refstring one by one 
    {
        for(j==0;j<_pageFrame;j++)
        {
            if(_refString[i]==pFrame[j]) // hit 
            {
                flag=1;
                for(k=0;k<_pageFrame;k++)
                {
                    fprintf(fp3,"%d ",pFrame[k]);
                }
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
            for(j=0;j<_pageFrame;j++)  
            {
                if(pFrame[j]==-1) // if page frame is not full
                {
                    flag2=1;
                    pFrame[j]=_refString[i];
                    for(k=0;k<_pageFrame;k++)
                    {
                        fprintf(fp3,"%d ",pFrame[k]);
                    }
                    fprintf(fp3,"!! page fault !!\n");
                    break; 
                }
            }

            if(flag2==1)
            {
                flag2=0;
                continue;
            }
            else if(flag2==0) // if page frame is full 
            {
                int res=-1; far=i+1;
                for(j=0;j<_pageFrame;j++)
                {
                    for(k=i+1;k<_refStringSize;k++)
                    {
                        if(pFrame[j]==_refString[k])
                        {
                            if(k>far)
                            {
                                far=k; // a refString index that comes latest
                                res=j;
                                flag3=1;
                            }
                            break;
                        }
                    }
                    if(k==_refStringSize) // a page that never comes again 
                    {
                        pFrame[j]=_refString[i];
                    }
                    else
                    {

                    }
                }
                pFrame[res]=_refString[i]; // change a page frame that comes latest  
                for(k=0;k<_pageFrame;k++)
                {
                        fprintf(fp3,"%d ",pFrame[k]);
                }
                fprintf(fp3,"!! page fault !!\n");

            }

        }
    }


    fprintf(fp3,"TOTAL PAGE FAULT : %d\n",faultCnt);
    fclose(fp3);
}

void fifoFunc(int _pageFrame,int _refStringSize,int* _refString)
{
    int faultCnt=0;
    int i,j,k;
    int flag=0; // hit check
    FILE* fp3 = fopen("output.txt","a");
    fprintf(fp3,"\n\nFIFO====================\n");
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
            if(pFrame.numOfData==_pageFrame) // queue is full
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
            else if(pFrame.numOfData<_pageFrame && pFrame.numOfData>-1) // queue is not full 
            {
                queueAdd(&pFrame,_refString[i]);
                while(search2!=NULL) // print memory state 
                {
                    fprintf(fp3,"%d ",search2->data);  

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

void lruFunc(int _pageFrame,int _refStringSize,int* _refString)
{
    int faultCnt=0;
    int i,j,k=0;
    int flag=0;
    FILE* fp3 = fopen("output.txt","a");
    fprintf(fp3,"\n\nLRU====================\n");




    fprintf(fp3,"TOTAL PAGE FAULT : %d\n",faultCnt);
    fclose(fp3);
}

void lfuFunc(int _pageFrame,int _refStringSize,int* _refString)
{
    int faultCnt=0;
    int i,j,k=0;
    int flag=0;
    FILE* fp3 = fopen("output.txt","a");
    fprintf(fp3,"\n\nLFU====================\n");

    dLinkedList list; 
    listInit(&list);

    dNode* search=list.head->next;
    dNode* search2=list.head->next;

    for(i=0;i<_refStringSize;i++)
        listInsert(&list,-1);

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

        search=list.head->next;
        search2=list.head->next;

        if(flag==1)
        {
            flag=0;
            continue;
        }
        else if(flag==0) // miss 
        {
            faultCnt++;
            if(list.numOfData==_pageFrame) // queue is full
            {
                listRemove(&list);
                listInsert(&list,_refString[i]);
                while(search2!=NULL) // print memory state 
                {
                    fprintf(fp3,"%d ",search2->data);
                    //printf("%d*",search2->data);
                    search2=search2->next;
                }
                fprintf(fp3,"!! page fault !!\n");  
            }
            else if(list.numOfData<_pageFrame && list.numOfData>-1) // queue is not full 
            {
                listInsert(&list,_refString[i]);
                while(search2!=NULL) // print memory state 
                {
                    fprintf(fp3,"%d ",search2->data);  

                    search2=search2->next;
                }
                fprintf(fp3,"!! page fault !!\n"); 
            }
        }
    }


    fprintf(fp3,"TOTAL PAGE FAULT : %d\n",faultCnt);
    fclose(fp3);
}

void wsFunc(int _page,int _windowSize,int _refStringSize,int* _refString)
{
    int faultCnt=0;
    int i,j,k=0;
    int flag=0;
    int out;
    int out2;
    int refSize=_refStringSize+_windowSize;
    int ref[refSize];

    FILE* fp3 = fopen("output.txt","a");
    fprintf(fp3,"\n\nWS====================\n");
    /* init pages */
    int Pages[_page]; // memory
    for(i=0;i<_page;i++)
        Pages[i]=-1;
    int WS[_windowSize]; // working set
    for(i=0;i<_windowSize;i++)
        WS[_windowSize]=-1; 

    // init ref[] for dealing with minus time 
    for(i=0;i<_refStringSize;i++)
        ref[i+_windowSize]=_refString[i];
    for(i=0;i<_windowSize;i++)
        ref[i]=-1;
    
    
    for(i=_windowSize+1;i<refSize;i++) // 
    {
        bubbleSort(Pages,_page);

        for(j=0;j<_windowSize;j++) // renew Woking Set
            WS[j]=ref[i-_windowSize+j];

        bubbleSort(WS,_windowSize);
        // WS update OK 

        for(j=0;j<_page;j++)
        {
            if((Pages[j]!=-1)&&(Pages[j]==ref[i])) // hit 
            {
                out=compFunc(Pages,WS,_page,_windowSize); // compare Pages&WS, remove elements in Pages not in WS
                flag=1;
                for(k=0;k<_page;k++)
                    fprintf(fp3,"%d ",Pages[k]);
                if(out!=-1)
                    fprintf(fp3,"<-%d out",out);
                fprintf(fp3,"\n");
                break;
            }
        }

        if(flag==1)
        {
            flag=0;
            continue;
        }
        else if(flag==0) // miss, something problem here 
        {
            faultCnt++;
            out2=compFunc(Pages,WS,_page,_windowSize);
            //Pages[in]=ref[i];
            for(k=0;k<_page;k++)
                fprintf(fp3,"%d ",Pages[k]);
            fprintf(fp3,"!! page fault !!");
            if(out2!=-1)
                fprintf(fp3,"<-%d out",out2);
            fprintf(fp3,"\n");
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

    FILE* fp = fopen("input.txt","r"); 
    
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

    FILE* fp2 = fopen("output.txt","w"); // make output.txt

    minFunc(pageFrame,refStringSize,refString);
    fifoFunc(pageFrame,refStringSize,refString);
    lruFunc(pageFrame,refStringSize,refString);
    lfuFunc(pageFrame,refStringSize,refString);
    wsFunc(page,windowSize,refStringSize,refString);

    fclose(fp2);

    printf("complete\n");

    return 0;
}