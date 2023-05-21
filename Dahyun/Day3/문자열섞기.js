function solution(str1, str2) {
    let str3;
    let str4=[];
    let answer;
    for(let i =0; i<str1.length; i++ ){
        
        str3 = str1[i] + str2[i];
        
        str4.push(str3);
    
        
        
        
    }
    
    answer=str4.join('');
    return answer;
}