# segment tree
from sys import stdin, setrecursionlimit
setrecursionlimit(10**6)


def build(start, end, idx):
    if start == end:
        seg_tree[idx] = num_list[start-1]
        return seg_tree[idx]

    mid = (start+end) // 2
    seg_tree[idx] = min(build(start, mid, idx*2), build(mid+1, end, idx*2+1))
    return seg_tree[idx]


def find(start, end, idx, l, r):
    if start > r or end < l:
        return 1e9+1

    if start >= l and end <= r:
        return seg_tree[idx]

    mid = (start + end) // 2
    return min(find(start, mid, idx*2, l, r), find(mid+1, end, idx*2+1, l, r))


n, m = map(int, stdin.readline().split())
seg_tree = [0] * (n * 4)
num_list = [int(stdin.readline()) for _ in range(n)]
build(1, n, 1)

for _ in range(m):
    a, b = map(int, stdin.readline().split())
    print(find(1, n, 1, a, b))
