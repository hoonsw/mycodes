#include <stdio.h>
#include <string.h>


int mul(char num1[], char num2[]) 
{
  char *num[2], *ptr;
  unsigned char mul[202];
  memset ( mul, 0x00, sizeof(char)*202 );
  int len[2], mul_len, i, j, k;
  num[0]= num1;
  num[1]= num2;

  len[0] = strlen(num1);
  len[1] = strlen(num2);

  mul_len = len[0] + len[1];

  for(i = 0; i < len[0]; i++)
	{
		for (j = 0; j < len[1]; j++) 
		{
    	k = mul_len - i - j;
      mul[k] += (num[0][len[0] - i - 1] - '0') * (num[1][len[1] - j - 1] - '0');
      if (mul[k] > 9) 
			{
      	mul[k - 1] += (mul[k] / 10);
        mul[k] %= 10;
      }
    }
	}

    for (i = 0; i <= mul_len; i++)
        mul[i] += '0';
    for (i = 0; mul[i] == '0';)
        i++;
    printf("%s", &mul[i]);

    return 0;
}


int sum(char num1[], char num2[]) 
{
	char sum[201] = {0,};
  int count, len1, len2;
  char *ptr1, *ptr2;

  if(strlen(num1) < strlen(num2)) 
	{
  	ptr1 = num2;
    ptr2 = num1;
  }
  else 
	{
    ptr1 = num1;
    ptr2 = num2;
  }

	len1 = strlen(ptr1);
	len2 = strlen(ptr2);

	sum[0] = '0';
	sum[len1 + 1] = 0x00;

	for(count = 0; count < len2; count++)
  	sum[len1 - count] = ptr1[len1 - count - 1] + (ptr2[len2 - count - 1] - '0');
	for(; count < len1; count++) sum[len1 - count] = ptr1[len1 - count - 1];


	for (count = len1; count > 0; count--)
	{
		if (sum[count] > '9') 
		{
    	sum[count - 1]++;
      sum[count] -= 10;
    }
	}

  printf("%s", (sum[0] == '0') ? &sum[1] : &sum[0]);
  return 0;
}


int main() 
{
  char oper;
  char num_a[101];
  char num_b[101];

  scanf("%c", &oper);
  scanf("%s", num_a);
  scanf("%s", num_b);
  if (oper == '*') 
	{
  	mul(num_a, num_b);
  } 
	else if (oper == '+') 
	{
  	sum(num_a, num_b);
  }
  return 0;
}

