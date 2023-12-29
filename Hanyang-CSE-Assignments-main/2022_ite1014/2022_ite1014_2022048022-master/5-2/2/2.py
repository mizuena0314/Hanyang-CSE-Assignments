def problemDescription():
    print("* Number of divisors *")

def getNumOfDivisors(number):
    cnt=0
    for i in range(1,number+1):
        if(number%i==0):
            cnt+=1
    return cnt

problemDescription()
num1 = int(input("Type the first number:\n"))
num2 = int(input("Type the second number:\n"))
print("Number of divisors of the first number is", getNumOfDivisors(num1))
print("Number of divisors of the second number is", getNumOfDivisors(num2))
