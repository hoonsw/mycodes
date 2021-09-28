polyPointer cpadd(polyPointer a, polyPointer b)
{
    polyPointer startA, c, lastC;
    int sum,done = FALSE;
    startA = a;

    a=a->link;
    b=b->link;

    c=getNode();
    c->expon=-1;

    lastC=c;

    do
    {
        switch()
    } while (/* condition */);
    
}
/* 첫 노드를 가리키느 ㄴ노드가 없으면 어떻게 cpadd()를 수정해야 하는지*/ 

/* polyPointer startB를 만들어 polyPointer b의 첫 노드를 지시하게 하고,
a->link == startA 와 b->link == startB를 포함한 조건문으로
각 항의 끝을 가르키는 노드에 이르렀는지를 파악한다 */ 

