function solution(cards1, cards2, goal) {
    var answer = "Yes";
    
    for (let s of goal) {
        if (cards1[0] == s) {
            cards1.shift();
        } else if (cards2[0] == s) {
            cards2.shift();
        } else {
            answer = "No";
        }
    }
    
    return answer;
}

//처음에 shift 함수를 사용할 생각을 못했었는데, shift 함수에 대해 알게 된 후 코드가 간결해졌다.
// shift함수 : 배열의 맨 앞에 값을 제거
