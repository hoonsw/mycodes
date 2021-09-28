void erase(polyPointer* ptr)
{
    polyPointer temp;
    while(*ptr)
    {
        temp=*ptr;
        *ptr=(*ptr)->link;
        free(temp);
    }
    for(;*ptr!=NULL;(*ptr)=(*ptr)->link)
    {
        temp=*ptr;
        free(temp);
    }
}