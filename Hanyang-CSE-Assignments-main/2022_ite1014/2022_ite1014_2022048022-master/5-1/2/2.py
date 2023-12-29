def add(x,y):
    return x+y

def sub(x,y):
    return x-y

def mul(x,y):
    return x*y

def div(x,y):
    return x/y

def mod(x,y):
    return x%y

def printMsg():
    print("completed")

x = int(input())
y = int(input())

print("sum:", add(x,y))
print("difference:", sub(x,y))
print("product:", mul(x,y))
print("division:", div(x,y))
print("remainder:", mod(x,y))
printMsg()