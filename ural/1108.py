N = int(input())

if N==1:
    print(2)
else:
    remain = 1
    for i in range(N):
        print(remain+1)
        remain = remain*(remain+1)


