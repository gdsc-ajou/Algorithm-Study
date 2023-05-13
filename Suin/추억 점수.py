def solution(name, yearning, photo):
    answer = []
    #리스트 2개로 dic 만들기
    yearning_dic = dict(zip(name, yearning))
    print(yearning_dic)

    for p in photo:
        sum = 0
        for people in p:
            score = yearning_dic.get(people,0)
            sum+=score
        answer.append(sum)
    #answer.append()
    return answer
