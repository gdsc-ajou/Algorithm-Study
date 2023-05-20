import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        HashMap<String, Integer> map = new HashMap();
        for(int i = 0; i < keymap.length; i++) {
            String[] arr = keymap[i].split("");
            for(int j = 0; j < arr.length; j++) {
                if(!map.containsKey(arr[j]) || map.get(arr[j]) > j + 1) {
                    map.put(arr[j], j + 1);
                }
            }
        }
        System.out.println(map);
        int[] answer = new int[targets.length];
        for(int i = 0; i < targets.length; i++) {
            answer[i] = 0;
            String[] arr = targets[i].split("");
            for(int j = 0; j < arr.length; j++) {
                if(map.containsKey(arr[j])) {
                    answer[i] += map.get(arr[j]);
                } else {
                    answer[i] = -1;
                    break;
                }
            }
        }
        return answer;
    }
}