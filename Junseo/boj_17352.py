# bfs
from sys import stdin
from collections import deque

n = int(stdin.readline())
visit = [False] * (n + 1)
edge_list = [[] for _ in range(n + 1)]
for _ in range(n-2):
    a, b = map(int, stdin.readline().split())
    edge_list[a].append(b)
    edge_list[b].append(a)

queue = deque([1])
visit[1] = True
while queue:
    x = queue.popleft()
    for nx in edge_list[x]:
        if not visit[nx]:
            visit[nx] = True
            queue.append(nx)
for i in range(2, n+1):
    if not visit[i]:
        print(1, i)
        break
