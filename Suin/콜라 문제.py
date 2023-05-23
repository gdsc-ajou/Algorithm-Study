def solution(a, b, n):
    answer=0
    while n>=a:
        remain = n%a
        new = (n//a)*b
        n=remain+new

        answer+=new
    return answer
