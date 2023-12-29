dict = {}
for i in range(3):
    res = input().split()
    name = res[0]
    score = int(res[1])
    dict[name] = score
to_find = input("Which student's score?\n")
if(to_find not in dict):
    print(to_find, "is not in the database.")
else:
    print(to_find+"'s score:", dict[to_find])