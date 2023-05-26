# two pointer
from sys import stdin

def binary_search(start, end, c):
    while start <= end:
        mid = (start + end) // 2
        if num_list[mid] == c:
            return True
        if num_list[mid] < c:
            start = mid + 1
        else:
            end = mid - 1
    return False


def two_pointer(start, end, c):
    while start < end:
        two_sum = num_list[start] + num_list[end]
        if two_sum == c:
            return True
        elif two_sum > c:
            end -= 1
        else:
            tmp = c - two_sum
            if num_list[start] != tmp and num_list[end] != tmp and binary_search(start+1, end-1, tmp):
                return True
            start += 1


n, c = map(int, stdin.readline().split())
num_list = sorted(list(map(int, stdin.readline().split())))

if binary_search(0, n-1, c):
    print(1)
elif two_pointer(0, n-1, c):
    print(1)
else:
    print(0)