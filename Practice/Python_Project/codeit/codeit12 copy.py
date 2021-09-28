def swap_elements(my_list,index1,index2):
    temp = my_list[index1]
    my_list[index1]=my_list[index2]
    my_list[index2]=temp

def partition(my_list,start,end):
    pivot = end
    bigger = start
    i = start

    while i<pivot:
        if my_list[i]<=my_list[pivot]:
            swap_elements(my_list,i,bigger)
            bigger+=1
        i+=1

    swap_elements(my_list,bigger,pivot)
    pivot=bigger

    return pivot

def quicksort(my_list,start,end):
    if end-start<1:
        return

    pivot = partition(my_list,start,end)
    quicksort(my_list,start,pivot-1)
    quicksort(my_list,pivot+1,end)