#include<stdio.h>
#include <string.h>
#define MAX 100  

int main(void)
{
   char op;
   char buf1[MAX + 1];
   char buf2[MAX + 1];
   char numstr1[MAX + 1];
   char numstr2[MAX + 1];
   char result[MAX + 2] = "";
   int i;
   int sum, carry = 0;
   char num[2][MAX + 1], *ptr;
   unsigned char mul[MAX + MAX + 2];
   int count, len[2], mul_len, j, k;

   scanf_s("%c", &op, sizeof(op));

   scanf_s("%s", buf1, sizeof(buf1));
   sprintf_s(numstr1, sizeof(numstr1), "%0100s", buf1);

   scanf_s("%s", buf2, sizeof(buf2));
   sprintf_s(numstr2, sizeof(numstr2), "%0100s", buf2);

   switch (op)
   {
   case '+':
      for (i = 99; i >= 0; i--)
      {
         sum = (numstr1[i] - '0') + (numstr2[i] - '0') + carry;
         carry = sum / 10;
         sum = sum % 10;
         result[i + 1] = sum + '0';
      }
      result[0] = carry + '0';

      for (i = 0; result[i] == '0'; i++);
      printf("%s\n", result + i);
      break;
   case '*':
      len[0] = strlen(numstr1);
      len[1] = strlen(numstr2);
      mul_len = len[0] + len[1]; /* 이게 마지막 자릿값입니다. 실제 길이는 이거보다 1 큼 */

      memset(mul, 0x00, mul_len + 2); /* mul 배열 초기화.. */
      for (i = 0; i < len[0]; i++)
         for (j = 0; j < len[1]; j++) /* 곱셈은.. 정수2부터 곱해짐.. */
         {
            k = mul_len - i - j; /* 뒷자리부터 연산.. 올림값 처리를 위해서.. */
            mul[k] += (numstr1[len[0] - i - 1] - '0') * (numstr2[len[1] - j - 1] - '0'); /* 곱함 */
            if (mul[k] > 9) { mul[k - 1] += (mul[k] / 10); mul[k] %= 10; } /* 올림값 처리 */
         }

      for (i = 0; i <= mul_len; i++) mul[i] += '0';  /* mul 배열을 문자화 */
      for (i = 0; mul[i] == '0'; ) i++; /* 앞자리가 0 이면 출력에서 제외하기 위해서 */
      printf("%s\n", &mul[i]);
      break;
   default:
      break;
   }

   return 0;
}