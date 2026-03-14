import sys
input = lambda:sys.stdin.readline().rstrip()

tt = int(input())

for _ in range(tt):
    n = int(input())
    a = list(map(int, input().split()))

    ans = (float)(n * a[0])
    print(ans)

    for x in a:
        print(x, end=" ")
    print()