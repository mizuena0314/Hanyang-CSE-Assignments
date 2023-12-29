words = input().split()

occurence = {}

for word in words:
    if(word not in occurence):
        occurence[word]=1
    else:
        occurence[word] += 1

for i in occurence.keys():
    print(i+":", occurence[i])