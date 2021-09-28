#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node* next;
    struct _node* prev;
} Node;

typedef struct _DList
{
    Node* head;
    Node* cur;
    int numofdata;
} DBList;

void ListInit(DBList* plist)
{
    plist->head=NULL;
    plist->numofdata=0;
}

void LInsert(DBList* plist, Data data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;

    newNode->next=plist->head;
    if(plist->head)
        plist->head->prev=newNode;
    
    newNode->prev=NULL;
    plist->head=newNode;

    (plist->numofdata)++;
}

int LFirst(DBList* plist, Data* pdata)
{
    if(plist->head==NULL)
        return FALSE;
    
    plist->cur=plist->head;
    *pdata=plist->cur->data;

    return TRUE;
}

int LNext(DBList* plist, Data* pdata)
{
    if(plist->cur->next==NULL)
        return FALSE;
    
    plist->cur=plist->cur->next;
    *pdata=plist->cur->data;

    return TRUE;
}

int LPrevious(DBList* plist, Data* pdata)
{
    if(plist->cur->prev==NULL)
        return FALSE;
    
    plist->cur=plist->cur->prev;
    *pdata=plist->cur->data;

    return TRUE;
}

int LCount(DBList* plist)
{
    return plist->numofdata;
}

