function solution(number, limit, power) {
    var answer = 0;
    let result = [];
    let num = 1;
    let sum = 0;
  
    while (num <= number) {
        for(let i=1; i<= num/2; i++) {
            if(num % i == 0 ) {
                sum+=1;
            }
        }
        sum++;
        result.push(sum);
        num++;
        sum=0;
    }
    
    for (let i=0; i<result.length; i++) {
        if(result[i]>limit) 
            result[i] = power;
        answer += result[i];
    }
    return answer;
}

// 이 문제는 첫 try 때 시간초과로 실패하였다. 첫 번째 for문에서 num/2가 아닌 num으로 범위를 설정하고 돌려서 시간초과가 떴었던 것으로 추측했다.
// 약수는 본래 값을 제외하고 n/2보다 클 수 없다는 점을 이용하여 1부터 현재 수의 절반까지만 반복문을 돌리니 시간초과 문제를 해결할 수 있었다.
// 이후 다시 sum++를 통해 본래 값인 num만 개수를 추가하는 것으로 해결할 수 있었다.
