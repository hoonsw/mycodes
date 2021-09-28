def merge(list1, list2):
    result = []
    i=0
    j=0

    while i<len(list1) and j<len(list2):
        if list1[i] > list2[j]:
            result.append(list2[j])
            j+=1
        else:
            result.append(list1[i])
            i+=1
    if i==len(list1):
        result+=list2[j:]
    elif j==len(list2):
        result+=list1[i:]

    return result

def merge_sort(result):

    if len(result)<=1:
        return result
    
    mid = len(result)//2
    
    left=result[:mid]
    right=result[mid:]
    
    left=merge_sort(left)
    right=merge_sort(right)
    
    return merge(left,right)

print(merge_sort([1, 3, 5, 7, 9, 11, 13, 11]))
print(merge_sort([28, 13, 9, 30, 1, 48, 5, 7, 15]))
print(merge_sort([2, 5, 6, 7, 1, 2, 4, 7, 10, 11, 4, 15, 13, 1, 6, 4]))
