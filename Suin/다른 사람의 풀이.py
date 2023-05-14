def solution(s):
    answer = []
    #빈 딕셔너리 만들기
    loc_dict = {} 
    #인덱스, 원소 동시 접근 -> enumerate
    for i, letter in enumerate(s):
        if letter in loc_dict : 
            answer.append(i-loc_dict[letter])
            #dic의 값 업데이트
            loc_dict[letter] = i
        else:
            #dic에 새로 값 추가
            loc_dict[letter] = i
            answer.append(-1)

    return answer
