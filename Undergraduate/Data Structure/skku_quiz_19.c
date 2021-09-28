
typedef struct listNode* listPointer;
typedef struct listNode
{
    char data[4];
    listPointer link;
};

void insert(listPointer *first, listPointer x)
{
    listPointer temp;
    malloc(temp, sizeof(*temp));
    *temp->data=50;
    if(*first)
    {
        temp->link=x->link;
        x->link=temp;
    }
    else 
    {
        temp->link=NULL;
        *first=temp;
    }
}

void delete(listPointer *first, listPointer x)
{
    listPointer temp;
    (*first)->link=temp;

    if(*first)
    {
        if(temp->link==NULL)
            (*first)->link=NULL;
        else
        {
            while((temp->link)!=NULL)
            {
                if(temp->link==x)
                    break;
                temp=temp->link;
            }
        temp->link=x->link;
        }
    }
    else 
        *first=(*first)->link;

    free(x);
}

delete(&list,list,y)