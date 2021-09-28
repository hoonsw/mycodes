def binary_search(element,some_list):
    start_index=0
    end_index=len(some_list)-1

    while start_index<=end_index:
        midpoint=(start_index+end_index)//2
        if some_list[midpoint]==element:
            return midpoint
        elif some_list[midpoint]>element:
            end_index=midpoint-1
        else:
            start_index=midpoint+1
    return None