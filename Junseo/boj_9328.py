# BFS
from sys import stdin
from collections import deque


def bfs(a, b):
    global doc
    queue = deque()
    if map_list[a][b] == '.':
        visit[a][b] = True
        queue.append([a, b])

    elif 65 <= ord(map_list[a][b]) <= 90:
        if key_list[ord(map_list[a][b]) - 65] == True:
            visit[a][b] = True
            queue.append([a, b])
        else:
            tmp_list[ord(map_list[a][b]) - 65].append([a, b])

    elif 97 <= ord(map_list[a][b]) <= 122:
        visit[a][b] = True
        queue.append([a, b])
        if key_list[ord(map_list[a][b]) - 97] == False:
            key_list[ord(map_list[a][b]) - 97] = True
            for mx, my in tmp_list[ord(map_list[a][b]) - 97]:
                visit[mx][my] = True
                queue.append([mx, my])

    elif map_list[a][b] == '$':
        visit[a][b] = True
        queue.append([a, b])
        doc += 1

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + move[i][0]
            ny = y + move[i][1]

            if 0 <= nx < h and 0 <= ny < w and (not visit[nx][ny]) and map_list[nx][ny] != '*':
                if map_list[nx][ny] == '.':
                    visit[nx][ny] = True
                    queue.append([nx, ny])

                elif 65 <= ord(map_list[nx][ny]) <= 90:
                    if key_list[ord(map_list[nx][ny]) - 65] == True:
                        visit[nx][ny] = True
                        queue.append([nx, ny])
                    else:
                        tmp_list[ord(map_list[nx][ny]) - 65].append([nx, ny])

                elif 97 <= ord(map_list[nx][ny]) <= 122:
                    visit[nx][ny] = True
                    queue.append([nx, ny])
                    if key_list[ord(map_list[nx][ny]) - 97] == False:
                        key_list[ord(map_list[nx][ny]) - 97] = True
                        for mx, my in tmp_list[ord(map_list[nx][ny]) - 97]:
                            visit[mx][my] = True
                            queue.append([mx, my])

                elif map_list[nx][ny] == '$':
                    visit[nx][ny] = True
                    queue.append([nx, ny])
                    doc += 1


t = int(stdin.readline())
move = [[0, 1], [0, -1], [1, 0], [-1, 0]]

for _ in range(t):
    h, w = map(int, stdin.readline().split())
    map_list = [list(stdin.readline().strip()) for _ in range(h)]
    visit = [[False] * w for _ in range(h)]
    key_input = list(stdin.readline().strip())
    key_list = [False] * 26
    tmp_list = list([] for _ in range(26))
    doc = 0
    if key_input[0] != '0':
        for i in key_input:
            key_list[ord(i) - 97] = True

    for i in range(h):
        if not visit[i][0] and map_list[i][0] != '*':
            bfs(i, 0)
        if not visit[i][w-1] and map_list[i][w-1] != '*':
            bfs(i, w-1)

    for j in range(w):
        if not visit[0][j] and map_list[0][j] != '*':
            bfs(0, j)
        if not visit[h-1][j] and map_list[h-1][j] != '*':
            bfs(h-1, j)

    print(doc)
