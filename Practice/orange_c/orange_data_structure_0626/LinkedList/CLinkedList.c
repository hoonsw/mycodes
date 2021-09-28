#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct struct_node
{
    Data data;
    struct _node* next;
} Node;

typedef struct _CLL
{
    Node* tail;
    Node* cur;
    Node* before;
    int numofdata;
} CList;

void ListInit(CList* plist)
{
    plist->tail=NULL;
    plist->cur=NULL;
    plist->before=NULL;
    plist->numofdata=0;
}

void LInsert(CList* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail==NULL)
    {
        plist->tail=newNode;
        newNode->next=newNode;
    }
    else
    {
        newNode->next=plist->tail->next;
        plist->tail->next=newNode;
        plist->tail=newNode;
    }
    (plist->numofdata)++;
}

void LInsertFront(CList* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;

    if(plist->tail==NULL)
    {
        plist->tail=newNode;
        newNode->next=newNode;
    }
    else
    {
        newNode->next=plist->tail->next;
        plist->tail->next=newNode;
    }
    (plist->numofdata)++;
}

int LFirst(CList* plist, Data* pdata)
{
    if(plist->tail==NULL)
        return FALSE;
    
    plist->before=plist->tail;
    plist->cur=plist->tail->next;

    *pdata=plist->cur->data;
    return TRUE;
}

int LNext(CList* plist, Data* pdata)
{
    if(plist->tail==NULL)
        return FALSE;

    plist->before=plist->cur;
    plist->cur=plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(CList* plist)
{
    Node* rpos=plist->cur;
    Data rdata = rpos->data;

    if(rpos==plist->tail)
    {
        if(plist->tail==plist->tail->next)
            plist->tail==NULL;
        else 
            plist->tail=plist->before; 
    }
    
    plist->before->next=plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numofdata)--;
    return rdata;
}

int LCount(CList* plist)
{
    return plist->numofdata;
}

