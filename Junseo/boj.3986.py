# stack
from sys import stdin

n = int(stdin.readline())
res = 0
for _ in range(n):
    string = stdin.readline().strip()
    stack = []

    for tmp in string:
        if not stack:
            stack.append(tmp)
        else:

            if tmp == stack[-1]:
                stack.pop()
            else:
                stack.append(tmp)

    if not stack:
        res += 1

print(res)
