def merge(list1, list2):
     result = []
     while len(list1)>0 or len(list2)>0:
         if len(list1)>0 and len(list2)>0:
             if list1[0]<list2[0]:
                 result.append(list1[0])
                 list1=list1[1:]
             else:
                 result.append(list2[1])
                 list2=list2[1:]
        elif len(list1)>0:
            result.append(list1[0])
            list1=list1[1:]
        elif len(list2)>0:
            result.append(list2[0])
            list2=list2[1:]
        
    return result

def merge_sort(result):
    if len(result)<=1:
        return result

    mid = len(result)//2

    left = result[:mid]
    right = result[mid:]

    left=merge_sort(left)
    right=merge_sort(right)

    return merge(left,right)