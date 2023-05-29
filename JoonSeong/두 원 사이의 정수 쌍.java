import java.util.*;
import java.io.*;

class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        long top = r2;
        long bottom = r1;
        for(long i = 1; i < r2; i++) {
            while(Math.sqrt(top * top + i * i) > r2) {
                top--;
            }
            if(i >= r1) {
                answer += top;
            } else {
                while(Math.sqrt(bottom * bottom + i * i) >= r1) {
                    bottom--;
                }
                answer += top - bottom;
            }
        }
        answer *= 4;
        answer += (r2 - r1 + 1) * 4;
        return answer;
    }
}