#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node* next;
} Node;

int main(void)
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* cur=NULL;

    Node* newNode = NULL;
    int readData;

    //데이터 입력//
    while(1)
    {
        printf("자연수 입력 : ");
        scanf("%d",&readData);
        if(readData<1)
            break;
        
        //노드 추가//
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next=NULL;

        if(head==NULL)
            head=newNode;
        else 
            tail->next=newNode;
        
        tail=newNode; // 테일이 연결 리스트의 끝을 가리킴 
    }
    printf("\n");

    //데이터 출력//
    if(head==NULL)
        printf("저장된 데이터 없음\n");
    else 
    {
        cur=head;
        printf("%d ",cur->data);

        while(cur->next)
        {
            cur=cur->next;
            printf("%d ",cur->data);
        }
    }
    printf("\n\n");

    //메모리 해체//
    if(head==NULL)
    {
        printf("해체할 노드 없음\n");
        return 0;
    }
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;

        printf("%d 삭제 \n",head->data);
        free(delNode);

        while(delNextNode)
        {
            delNode=delNextNode;
            delNextNode=delNextNode->next;

            printf("%d 삭제 \n",delNode->data);
            free(delNode);
        }
    }
    
    return 0;
}