# segment tree
from sys import stdin, setrecursionlimit
setrecursionlimit(10**6)


def build(start, end, idx):
    if start == end:
        seg_tree[idx] = [num_list[start-1], num_list[start-1]]
        return seg_tree[idx]

    mid = (start+end) // 2
    left, right = build(start, mid, idx*2), build(mid+1, end, idx*2+1)
    seg_tree[idx] = [min(left[0], right[0]), max(left[1], right[1])]
    return seg_tree[idx]


def find(start, end, idx, l, r):
    if start > r or end < l:
        return [1e9+1, 0]

    if start >= l and end <= r:
        return seg_tree[idx]

    mid = (start + end) // 2
    left, right = find(start, mid, idx*2, a,
                       b), find(mid+1, end, idx*2+1, a, b)
    return [min(left[0], right[0]), max(left[1], right[1])]


n, m = map(int, stdin.readline().split())
seg_tree = [[] for _ in range(n * 4)]
num_list = [int(stdin.readline()) for _ in range(n)]
num_len = len(num_list)
build(1, n, 1)

for _ in range(m):
    a, b = map(int, stdin.readline().split())
    print(*find(1, n, 1, a, b))
