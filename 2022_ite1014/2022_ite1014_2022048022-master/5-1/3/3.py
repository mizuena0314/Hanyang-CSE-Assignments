def addTotal(n):
    return (((n*n)+n)//2)

def mulTotal(n):
    global gMul
    gMul = 1
    for i in range(1, n+1):
        gMul *= i

n = int(input())
mulTotal(n)
print("addTotal():", addTotal(n))
print("gMul:", gMul)