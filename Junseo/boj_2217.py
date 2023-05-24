# greedy
from sys import stdin

n = int(stdin.readline())
rope = sorted([int(stdin.readline()) for _ in range(n)], reverse=True)

res = 0
for i, val in enumerate(rope):
    res = max(res, (i+1)*val)
print(res)