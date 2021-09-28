typedef struct queue* queuePointer;
typedef struct queue
{
    element data;
    queuePointer link;
};
queuePointer front[MAX_QUEUES],rear[MAX_QUEUES];

void addq(int i, element item)
{
    queuePointer temp;
    temp = (queuePointer)malloc(sizeof(*temp));

    if(front[i])
    {
        temp->link=front[i]->link; //
        while((temp->link)!=NULL)
        {
            temp=temp->link;
        }
        temp->data=item;
        temp->link=NULL;
    }
    else 
    {   temp->data=item;
        temp->link=NULL;
        front[i]=temp;
    }
}