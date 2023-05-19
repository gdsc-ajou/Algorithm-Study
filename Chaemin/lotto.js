function solution(lottos, win_nums) {
    const correct = lottos.filter((lotto) => win_nums.includes(lotto)).length;
    const zero = lottos.filter((lotto) => lotto === 0).length;
    
    let low = 7 - correct > 6 ? 6 : 7 - correct;
    let high = low - zero < 1 ? 1 : low - zero;
    
    var answer = [high, low];
    return answer;
    
}
