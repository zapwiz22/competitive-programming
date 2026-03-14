import random 

tt = 1
print(tt)

for i in range(tt):
    n = random.randrange(1,5)
    print(n)

    for i in range(n):
        print(random.randrange(1,100), end=" ")
    print()