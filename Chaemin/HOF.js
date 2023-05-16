function solution(k, score) {
    const list = [];
    const result = [];
    const dayNum = score.length;
    const temp = [];
    
    for (let i=0; i<dayNum; i++) {

        temp.push(score[i]);
        temp.sort((a,b) => b-a);
        const list = temp.slice(0,k);
        result.push(list.at(-1));
    }
    return result;
}
