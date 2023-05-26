import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String s) {
        ArrayList<Integer> arrList = new ArrayList();
        HashMap<String, Integer> map = new HashMap();
        for(int i = 0; i < s.length(); i++) {
            String current = s.split("")[i];
            if(map.containsKey(current)) {
                arrList.add(i - map.get(current));
            } else {
                arrList.add(-1);
            }
            map.put(current, i);
        }
        int[] answer = arrList.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}