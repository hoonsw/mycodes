def binary_search(element, some_list,start_index=0,end_index=None):
    if end_index==None:
        end_index=len(some_list)-1

    if start_index>end_index:
        return None

    mid = (start_index+end_index)//2

    if some_list[mid]==element:
        return mid

    if element<some_list[mid]:
        return binary_search(element,some_list,start_index,mid-1)

    else:
        return binary_search(element,some_list,mid+1,end_index)