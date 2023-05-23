function solution(a, b) {
    let ab = parseInt(String(a) + String(b));
    return ab>2*a*b ? ab : 2*a*b
}