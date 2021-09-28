# 두 요소의 위치를 바꿔주는 helper function
def swap_elements(my_list, index1, index2):
    # 코드를 작성하세요.
    temp=my_list[index1]
    my_list[index1]=my_list[index2]
    my_list[index2]=temp


# 퀵 정렬에서 사용되는 partition 함수
def partition(my_list, start, end):
    # 코드를 작성하세요.
    pivot_index = len(my_list)-1
    bigger = start
    i = start
    for j in range(i,end):
        if my_list[j]>=my_list[pivot_index]:
            i+=1
        else:
            swap_elements(my_list,bigger,i)
            bigger+=1
            i+=1
    swap_elements(my_list,pivot_index,bigger)
    temp = pivot_index
    pivot_index=bigger
    bigger=temp
    return pivot_index


# 테스트 1
list1 = [4, 3, 6, 2, 7, 1, 5]
pivot_index1 = partition(list1, 0, len(list1) - 1)
print(list1)
print(pivot_index1)

# 테스트 2
list2 = [6, 1, 2, 6, 3, 5, 4]
pivot_index2 = partition(list2, 0, len(list2) - 1)
print(list2)
print(pivot_index2)
