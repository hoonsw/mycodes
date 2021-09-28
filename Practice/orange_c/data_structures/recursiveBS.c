#include <stdio.h>

RecurBSearch(int ar[],int first, int last, int target)
{
    int mid;
    if(first>last)
    return -1;
    mid=(first+last)/2;

    if(ar[mid]==target)
    return mid;
    else if(target<ar[mid])
    return RecurBSearch(ar, first,mid-1,target);
    else 
    return RecurBSearch(ar,mid+1,last,target);
}

int main(void)
{
    int arr[]={1,3,5,7,9};
    int idx;

    idx = RecurBSearch(arr,0,sizeof(arr)/sizeof(int)-1,7);

    if(idx==-1)
    printf("Å½»ö ½ÇÆĞ \n");
    else
    printf("Å¸°Ù : %d \n",idx);

    return 0;    
}