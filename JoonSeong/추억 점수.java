import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        HashMap<String, Integer> score = new HashMap();
        for(int i = 0; i < name.length; i++) {
            score.put(name[i], yearning[i]);
        }
        int[] answer = new int[photo.length];
        
        for(int i = 0; i < photo.length; i++) {
            answer[i] = 0;
            for(int j = 0; j < photo[i].length; j++) {
                if(score.containsKey(photo[i][j])) {
                answer[i] += score.get(photo[i][j]);
                }
            }
        }
        return answer;
    }
}