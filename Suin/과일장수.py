def solution(k, m, score):
    answer = 0
    score.sort(reverse=True)#내림차순 정렬
    #print(score)

    for pivot in range(0,len(score)-1,m):
        if(len(score[pivot:pivot+m])<m):
            break
        answer += score[pivot+m-1]*m
    return answer
