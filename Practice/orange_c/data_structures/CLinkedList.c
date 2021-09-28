#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist)
{
    plist->tail=NULL;
    plist->cur=NULL;
    plist->before=NULL;
    plist->numofData=0;
}

void LInsert(List* plist, Data data) // 꼬리에 노드를 추가
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
        plist->tail=newNode;
    }
    (plist->numofData)++;
}

void LInsertFront(List* plist, Data data) // 머리에 노드를 추가
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
    (plist->numofData)++;
}

int LFirst(List* plist, Data* pdata)
{
    if(plist->tail==NULL)
        return FALSE;
    
    plist->before=plist->tail;
    plist->cur=plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List* plist, Data* pdata)
{
    if(plist->tail==NULL)
        return FALSE;
    
    plist->before=plist->cur;
    plist->cur=plist->cur->next;

    *pdata=plist->cur->data;
    return TRUE;
}

Data LRemove(List* plist)
{
    Node* rpos=plist->cur;
    Data rdata = rpos->data;

    if(rpos==plist->tail)
    {
        if(plist->tail==plist->cur->next)
            plist->tail=NULL;
        else 
            plist->tail=plist->before;
    }

    plist->before->next=plist->cur->next;
    plist->cur=plist->before;

    free(rpos);
    (plist->numofData)--;
    return rdata;
}

int LCount(List* plist)
{
    return plist->numofData;
}