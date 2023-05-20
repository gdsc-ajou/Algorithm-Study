import java.util.*;
import java.io.*;

class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 1;
        int start = section[0], end = section[0] + m - 1;
        for(int i = 0; i < section.length; i++) {
            if(section[i] > end) {
                start = section[i];
                end = start + m - 1;
                answer++;
            }
        }
        return answer;
    }
}