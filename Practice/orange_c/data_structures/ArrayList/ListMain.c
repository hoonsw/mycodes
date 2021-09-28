#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c"

int main(void)
{
	List list;
	int data;
	ListInit(&list);
	int sum=0;

	for(int i=0;i<9;i++)
		LInsert(&list,i+1);
	
	printf("현재 데이터의 수 : %d \n",LCount(&list));

	if(LFirst(&list,&data))
	{
		printf("%d ",data);
		
		while(LNext(&list,&data))
			printf("%d ",data);
	}

	printf("\n\n");

	if(LFirst(&list,&data))
	{
		sum+=data;

		while(LNext(&list,&data))
			sum+=data;
	}

	printf("합 : %d",sum);

	if(LFirst(&list,&data))
	{
		if(data%2==0||data%3==0)
			LRemove(&list);

		while(LNext(&list,&data))
		{
			if(data%2==0||data%3==0)
				LRemove(&list);
		}
	}

	printf("\n");

	if(LFirst(&list,&data))
	{
		printf("%d ",data);

		while(LNext(&list,&data))
			printf("%d ",data);
	}

	return 0;
}