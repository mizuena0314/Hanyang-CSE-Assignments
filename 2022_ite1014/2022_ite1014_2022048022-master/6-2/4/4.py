import random
import sys

def getRandomCheese(leng):
    ls = []
    for i in range(leng):
        ls.append(chr(random.randint(97,122)))
    cheese = ''.join(ls)
    return cheese
while(1):
    cheese_size = int(input("Input the length of the string : "))
    if(10<=cheese_size<=30):
        break
while(1):
    tc = int(input("How many times will the mouse eat? : "))
    if(1<=tc<=10):
        break
cheese = getRandomCheese(cheese_size)
print("Generated Cheese is '"+cheese+"'")

temp = []
for it in range(cheese_size):
    temp.append(cheese[it])
eaten = []
for i in range(tc):
    while(1):
        cur = chr(random.randint(97,122))
        if(cur not in eaten):
            break
    eaten.append(cur)
    print("Start eating '"+cur+"'")
    if(''.join(temp) == "_"*cheese_size):
        print("Out of cheese!")
        sys.exit(0)
    for j in range(cheese_size):
        if(temp[j]==cur):
            temp[j]="_"
    print("Eaten alphabet of cheese :", " ".join(eaten))
    print("Original cheese : '"+cheese+"'")
    print("Current cheese status : '"+''.join(temp)+"'")
    print()

print("Finally remained Cheese Status :")
print("Eaten alphabet of cheese :", " ".join(eaten))
print("Original cheese : '"+cheese+"'")
print("Current cheese status : '"+''.join(temp)+"'")