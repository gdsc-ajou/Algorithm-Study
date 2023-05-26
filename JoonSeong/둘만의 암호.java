import java.util.*;
import java.io.*;

class Solution {
    public String solution(String s, String skip, int index) {
        ArrayList<String> arrList = new ArrayList();
        for(int i = 97; i <= 122; i++) {
            arrList.add(String.valueOf((char)i));
        }
        for(int i = 0; i < skip.length(); i++) {
            arrList.remove(skip.substring(i, i + 1));
        }
        char[] arr = s.toCharArray();
        String answer = "";
        for(int i = 0; i < arr.length; i++) {
            int idx = arrList.indexOf(String.valueOf(arr[i]));
            idx = (idx + index) % arrList.size();
            arr[i] = arrList.get(idx).charAt(0);
            answer += String.valueOf(arr[i]);
        }
        return answer;
    }
}