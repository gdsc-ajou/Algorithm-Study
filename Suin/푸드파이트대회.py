def solution(food):
    answer = ''
    #food[0]은 물
    for i in range(1,len(food)):
        # 몫 연산자 = //
        n = food[i]//2
        answer+=str(i)*n
        print(answer)
    #arr[::-1] = 역순
    answer +=(str(0)+answer[::-1])
    print(answer)
    return answer
