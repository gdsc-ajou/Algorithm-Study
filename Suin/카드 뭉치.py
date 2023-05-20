def solution(cards1, cards2, goal):
    answer = 'Yes'
    cards1_idx, cards2_idx = 0, 0

    for word in goal:
        #조건문은 앞에서부터 차례대로 판단됨
        if cards1_idx<len(cards1) and word == cards1[cards1_idx]:
            cards1_idx +=1
        elif cards2_idx<len(cards2) and word == cards2[cards2_idx]:
            cards2_idx +=1
        else: 
            answer = 'No'
            break

    return answer
