def solution(n):
    answer = 0
    
    for i in str(n):
        answer+=int(i)
        print(str(answer))
    return answer
