#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node* next;
} Node; 

typedef struct _linkedList
{
    Node* head;
    Node* cur;
    Node* before;
    int numofdata;
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist)
{
    plist->head=(Node*)malloc(sizeof(malloc));
    plist->head->next=NULL;
    plist->comp=NULL;
    plist->numofdata=0;
}

void FInsert(List* plist, LData data)
{
    Node* newNode = (Node*)malloc(sizeof(malloc));
    newNode->data=data;

    newNode->next=plist->head->next;
    plist->head->next=newNode;

    (plist->numofdata)++;
}

void SInsert(List* plist, LData data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    Node* pred=plist->head;
    newNode->data=data;

    while(pred->next!=NULL && plist->comp(data,pred->next->data)!=0)
    {
        pred=pred->next;
    }

    newNode->next=pred->next;
    pred->next=newNode;

    (plist->numofdata)++;
}

void LInsert(List* plist, LData data)
{
    if(plist->comp==NULL)
        FInsert(plist,data);
    else 
        SInsert(plist,data);
}

int LFirst(List* plist, LData* pdata)
{
    if(plist->head->next==NULL)
        return FALSE;
    
    plist->before=plist->cur;
    plist->cur=plist->cur->next;

    *pdata=plist->cur->data;
    return TRUE; 
}

LData LRemove(List* plist)
{
    Node* rpos=plist->cur;
    LData rdata = rpos->data;

    plist->before->next=plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numofdata)--;
    return rdata;
}

int LCount(List* plist)
{
    return plist->numofdata;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
    plist->comp=comp; 
}

int WhoIsPrecede(int d1, int d2)
{
    if(d1<d2)
        return 0;
    else 
        return 1; 
}

int main(void)
{
    //리스트 생성과 초기화//
    List list; 
    int data;
    ListInit(&list);

    LInsert(&list, 11); LInsert(&list, 22);

    printf("데이터 수 %d \n",LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ",data);

        while(LNext(&list, &data))
            printf("%d ",data);
    }
    printf("\n\n");

    //22를 검색 후 모두 삭제//
    if(LFirst(&list, &data))
    {
        if(data==22)
            LRemove(&list);

        while(LNext(&list, &data))
        {
            if(data==22)
                LRemove(&list);
        }
    }

    //삭제 후 남은 데이터 출력//
    printf("데이터 수 %d \n",LCount(&list));

    if(LFirst(&list,&data))
    {
        printf("%d ",&data);

        while(LNext(&list, &data))
            printf("%d ",data);
    }
    printf("\n\n");
    return 0;
}