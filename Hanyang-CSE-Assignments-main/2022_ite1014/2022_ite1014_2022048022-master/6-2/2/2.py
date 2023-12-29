import random

def findMax(ls):
    largest = 0
    for i in range(100):
        if(ls[i]>largest):
            largest = ls[i]
    return largest

def findMin(ls):
    smallest = 987654321
    for i in range(100):
        if(ls[i]<smallest):
            smallest = ls[i]
    return smallest

my_list = []
for i in range(100):
    num = random.randint(1,1000)
    print(num, end = ' ')
    my_list.append(num)
print()

print("max value:", findMax(my_list))
print("min value:", findMin(my_list))