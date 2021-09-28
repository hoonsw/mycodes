#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	head = (Node*)malloc(sizeof(Node));
	tail = head; 

	/*데이터 입력*/
	while(1)
	{
		printf("자연수 입력 : ");
		scanf("%d",&readData);
		if(readData<1)
			break;

		/* 노드 추가 */
		newNode=(Node*)malloc(sizeof(Node));
		newNode->data=readData;
		newNode->next=NULL;

		tail->next=newNode;
		tail=newNode; 
	}
	printf("\n");

	/*입력받은 데이터의 출력*/
	printf("입력받은 데이터의 전체출력 \n");

	if(head==tail)
		printf("저장된 수 없음\n");
	else 
	{
		cur=head;

		while(cur->next)
		{
			cur=cur->next;
			printf("%d ",cur->data);
		}
	}
	printf("\n\n");

	/*메모리 해제*/
	
	if(head==NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		while(delNextNode)
		{
			delNode=delNextNode;
			delNextNode=delNextNode->next;
			printf("%d를 삭제 \n",delNode->data);
			free(delNode);
		}
	}
	
	return 0;
}
 

 