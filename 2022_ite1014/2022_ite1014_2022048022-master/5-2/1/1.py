def printLine(n):
    for i in range(n):
        print(i+1, end=' ')

n = int(input())
for i in range(1,n+1):
    printLine(i)
    print()
for i in range(n,0,-1):
    printLine(i)
    print()
