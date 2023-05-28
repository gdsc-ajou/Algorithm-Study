function solution(s, skip, index) {
    // 1) filter 함수를 사용하여 skip문자를 제거 배열을 반환 받는다.
    const alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z'];
    
    const arr = alphabet.filter((a) => !skip.includes(a));
    console.log(arr.length);
    
    // 2) map 함수를 사용하여  (현재 알파벳) + index에 위차한 값을 반환한다. 
    return s.split('').map((a) => arr[(arr.indexOf(a)+index) % arr.length]).join('');
}

// 처음에 이중 for문을 사용해서 테스트 부분에서 시간 초과 및 에러가 떠서 아예 코드를 갈아엎었다.
// 가장 어려웠던 부분은 알파벳을 다시 순환하는 부분이었다. arr.length로 나눈 나머지를 index로 사용하는 것이 어려워서 이 부분은 서치를 통해 코드를 수정하였다.
// 내장된 함수를 잘 사용해야겠다는 생각도 들었다. ex) map, indexOf
