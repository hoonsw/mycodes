#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Add(char* op1, char* op2)
{
    char add[102]={0,};
    int count, len1, len2;
    char *ptr1, *ptr2;

    if(strlen(op1) < strlen(op2)) 
	{
        ptr1 = op2;
        ptr2 = op1;
    }
    else 
	{
        ptr1 = op1;
        ptr2 = op2;
    }

	len1 = strlen(ptr1);
	len2 = strlen(ptr2);

	add[0] = '0';
	add[len1 + 1] = 0x00;

	for(count = 0; count < len2; count++)
  	add[len1 - count] = ptr1[len1 - count - 1] + (ptr2[len2 - count - 1] - '0');
	for(; count < len1; count++) add[len1 - count] = ptr1[len1 - count - 1];


	for (count = len1; count > 0; count--)
	{
		if (add[count] > '9') 
		{
            add[count - 1]++;
            add[count] -= 10;
        }
	}

    printf("%s", (add[0] == '0') ? &add[1] : &add[0]);
    return 0;
}

int Multiply(char* op1, char* op2)
{
    char result[202]; 
    int n,i,j;

    int len[2];
    len[0] = strlen(op1); len[1] = strlen(op2);
    int result_len=len[0]+len[1];

    memset(result,0x00,result_len+2);

    for(i=0;i<len[0];i++)
    {
        for(j=0;j<len[1];j++)
        {
            n=result_len-i-j;
            result[n]+=(op1[len[0]-1-i]-'0')*(op2[len[1]-1-j]-'0');
            if(result[n]>9)
            {
                result[n-1]+=(result[n]/10);
                result[n]%=10;
            }
        }
    }

    for(i=0;i<result_len;i++)
        result[i]+='0';
    for(i=0;result[i]=='0';) i++;

    printf("%s",&result[i]);
    return 0;
}

int main(void)
{
    char operator;
    char op1[101];
    char op2[101];

    scanf("%c",&operator);
    scanf("%s",op1);
    scanf("%s",op2);

    if(operator=='+')
        Add(op1,op2);
    else if(operator=='*')
        Multiply(op1,op2);
    
    return 0;
}