function solution(a, b) {
    let a_front = parseInt(String(a) + String(b));
    let b_front = parseInt(String(b) + String(a));
    
    return a_front>= b_front ? a_front : b_front

} 