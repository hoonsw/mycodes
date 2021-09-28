#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define COMPARE1(a, b)	(++(*cnt) && (a*2017)%10000 > (b*2017)%10000)
#define COMPARE2(a, b)	(++(*cnt) && (a*2017)%10000 >= (b*2017)%10000)
#define MAX_SIZE 1000000

/* Modify from here */
// You can add additional user-defined functions here
void InsertionSort(int* list, int n, int *cnt)
{
	int i,j,temp=0;
	printf("n : %d\n",n);
	for(i=1;i<n;i++)
	{
		temp=list[i];
		for(j=i-1;j>=0;j--)
		{
			if(COMPARE1(list[j],temp))
				list[j+1]=list[j];
			else 
				break;
		}
		list[j+1]=temp;
	}
}

void merge(int* list, int* cnt, int left, int center, int right)
{
	int i=left;
	int j=center+1;
	int cur=left;
	int *sorted=(int*)malloc(sizeof(int)*MAX_SIZE);

	while( (center>=i) && (right>=j) )
	{
		if(COMPARE2(list[j],list[i]))
			sorted[cur++]=list[i++];
		else 
			sorted[cur++]=list[j++];
	}

	while(center>=i)
	{
		sorted[cur++]=list[i++];
	}

	for(int idx=left;cur>idx;idx++)
		list[idx]=sorted[idx];
	
	free(sorted);
}

void mergeSort(int* list, int* cnt, int left, int right)
{
	int center;
	if(COMPARE1(right,left))
	{
		center=(left+right)/2;
		mergeSort(list,cnt,left,center);
		mergeSort(list,cnt,center+1,right);
		merge(list,cnt,left,center,right);
	}
}

/* Modify to here */

void Solution(int *list, int n, int *cnt) {
/* Modify from here */
  //you can compare the two numbers using COMPARE1(list[0],list[1]);
  //you can compare the two numbers using COMPARE2(list[0],list[1]);
	if(n<15)
		InsertionSort(list, n, cnt);
	else if(n>=15&&n<=100000)
	{
		mergeSort(list, cnt, 0, n-1);
	}
	else 
		printf("error\n");

/* Modify to here */
}




int main() {
	int i, n, *list, *read, cnt = 0;

	scanf("%d", &n);
	list = malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	
	Solution(list, n, &cnt);

  	printf("Encrypted Data\n");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
		
	}
  	printf("\nDecrypted Data\n");
	for (i = 0; i < n; i++) {
		printf("%d ", list[i] * 2017 % 10000);
		
	}

		
		
	printf("\nThe number of comparisons: %d\n",cnt);
	
	free(list);
	return 0;
}

