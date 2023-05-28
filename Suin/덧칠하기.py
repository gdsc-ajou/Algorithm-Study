def solution(n, m, section):
    answer = 0
    #시작점
    point = section[0]
    for i in range(len(section)):

        if section[i]-point >=m:
            answer+=1 
            point=section[i]
    answer+=1
    return answer
