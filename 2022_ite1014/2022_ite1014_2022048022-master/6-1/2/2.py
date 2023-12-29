dict = {}
for i in range(2,10,2):
    dict[i] = []
    for j in range(1,10):
        dict[i].append(i*j)
print(dict)