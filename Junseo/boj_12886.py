# bfs
from sys import stdin
from collections import deque

num_list = list(map(int, stdin.readline().split()))
l = sum(num_list)
if sum(num_list) % 3 != 0:
    print(0)
    exit(0)
    
visit = [[False] * (1501) for _ in range(1501)]
num_list.sort()
visit[num_list[0]][num_list[1]] = True
queue = deque([num_list])

while queue:
    sub = queue.popleft()
    
    if sub[0] == sub[1] and sub[1] == sub[2]:
        print(1)
        exit(0)
    
    if sub[0] < sub[1] and 2*sub[0] <= 1500:
        tmp = sorted([2*sub[0], sub[1]-sub[0], sub[2]])
        if not visit[tmp[0]][tmp[1]]:
            visit[tmp[0]][tmp[1]] = True
            queue.append(tmp)

    if sub[1] < sub[2] and 2*sub[1] <= 1500:
        tmp = sorted([sub[0], 2*sub[1], sub[2]-sub[1]])
        if not visit[tmp[0]][tmp[1]]:
            visit[tmp[0]][tmp[1]] = True
            queue.append(tmp)
    
    if sub[0] < sub[2] and 2*sub[0] <= 1500:
        tmp = sorted([2*sub[0], sub[1], sub[2]-sub[0]])
        if not visit[tmp[0]][tmp[1]]:
            visit[tmp[0]][tmp[1]] = True
            queue.append(tmp)

print(0)