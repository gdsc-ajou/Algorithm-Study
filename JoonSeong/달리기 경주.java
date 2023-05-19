import java.util.*;
import java.io.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for(int i = 0; i < players.length; i++) {
            map.put(players[i], i);
        }
        for(int i = 0; i < callings.length; i++) {
            int idx1 = map.get(callings[i]);
            int idx2 = map.get(callings[i]) - 1;
            String str1 = players[idx1];
            players[idx1] = players[idx2];
            players[idx2] = str1;
            map.put(players[idx1], idx1);
            map.put(players[idx2], idx2);
            
        }
        String[] answer = players;
        return answer;
    }
}