
from math import sqrt

def distance(store1, store2):
    return sqrt((store1[0] - store2[0]) ** 2 + (store1[1] - store2[1]) ** 2)

def closest_pair(coordinates):
    closer = 0
    for i in coordinates:
        for j in coordinates:
            if closer<distance(i,j):
                closer=distance(i,j)
    return closer

test_coordinates = [(2, 3), (12, 30), (40, 50), (5, 1), (12, 10), (3, 4)]
print(closest_pair(test_coordinates))

 