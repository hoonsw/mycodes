int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen=strlen(exp);
    int i;
    char tok,op1,op2;

    StackInit(&stack);

    for(i=0;i<expLen;i++) // 수식을 구성하는 문자 각각을 대상으로 반복
    {
        tok=exp[i]; // 한 문자씩 tok에 저작
        if(isdigit(tok)) // 문자가 정수인지 확인
        {
            SPush(&stack, tok-'0'); //정수면 숫자로 변환 후 스택에 푸시
        }
        else // 연산자의 경우 
        {
            op2 = SPop(&stack); // 스택에서 두번째 연산자 꺼내기
            op1 = SPop(&stack); // 스택에서 첫번째 연산자 꺼내기 
        
        
            switch(tok) // 연산하고 결과를 스택에 푸시
            {
                case '+':
                    SPush(&stack,op1+op2);
                    break;
                case '-':
                    SPush(&stack,op1-op2);
                    break;
                case '*':
                    SPush(&stack,op1*op2);
                    break;
                case '/':
                    SPush(&stack,op1/op2);
                    break;
            }
        }
    }
    return SPop(&stack); // 마지막 연산결과를 스택에서 꺼내 연산 
}