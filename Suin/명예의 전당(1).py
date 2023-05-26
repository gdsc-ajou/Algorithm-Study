def solution(k, score):
    answer = []
    stack = []
    for i in range(len(score)):
        if i>=0 and i<k:
            stack.append(score[i])
            #내림차순 정렬
            stack.sort(reverse=True)
            #마지막 요소 접근
            answer.append(stack[-1])
        else:
            if(stack[-1]<=score[i]):
                stack.append(score[i])
                #내림차순 정렬
                stack.sort(reverse=True)
                stack.pop()
                #마지막 요소 접근
                answer.append(stack[-1])
            else:
                answer.append(stack[-1])

    return answer
