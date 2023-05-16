# two pointer
from sys import stdin

n = int(stdin.readline())
num_list = sorted(list(map(int, stdin.readline().split())))
l, r = 0, n-1
ans = abs(num_list[l] + num_list[r])
res = [num_list[l], num_list[r]]

while l < r:

    cal = num_list[l] + num_list[r]
    tmp = abs(cal)
    if ans > tmp:
        ans = tmp
        res = [num_list[l], num_list[r]]

    if cal >= 0:
        r -= 1
    else:
        l += 1

print(*res)
