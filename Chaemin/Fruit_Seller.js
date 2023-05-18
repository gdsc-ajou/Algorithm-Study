function solution(k, m, score) {
    let answer = [];
    let boxNum = Math.floor(score.length / m);
    let result = 0;
    
    let sortedScore = score.slice().sort((a,b) => b-a);
    
    for (let i=0; i<boxNum; i++) {
        let box = sortedScore.slice(i*m,(i+1)*m);
        answer.push(...box);
        result += answer.at(-1) * m;
    }
    
    return result;
}

// 처음에 splice()를 사용하여 진행하였다가, 시간 초과 문제로 인해 방식을 바꾸었다.
// score 배열의 크기에 따라 반복문이 많은 횟수로 실행되기 때문
// splice()는 배열의 요소를 제거하는 작업을 수행, 요소를 제거한 후에 배열의 크기가 줄어들게 되는데, 이 과정에서 반복문이 많은 횟수로 실행되면서 성능저하가 발생한다.
