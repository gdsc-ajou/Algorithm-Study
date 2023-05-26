import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        int todayYear = Integer.valueOf(today.split("\\.")[0]);
        int todayMonth = Integer.valueOf(today.split("\\.")[1]);
        int todayDate = Integer.valueOf(today.split("\\.")[2]);
        
        ArrayList<Integer> arrList = new ArrayList();
        for(int i = 0; i < privacies.length; i++) {
            String privacyTerm = privacies[i].split(" ")[1];
            int deleteMonth = 0;
            for(int j = 0; j < terms.length; j++) {
                if(terms[j].split(" ")[0].equals(privacyTerm)) {
                    deleteMonth = Integer.valueOf(terms[j].split(" ")[1]);
                    break;
                }
            }
            int year = Integer.valueOf(privacies[i].split("\\.")[0]);
            int month = Integer.valueOf(privacies[i].split("\\.")[1]);
            int date = Integer.valueOf(privacies[i].split("\\.")[2].split(" ")[0]);
            month += deleteMonth;
            date--;
            if(date <= 0) {
                date = 28;
                month--;
            }
            while(month >= 13) {
                month -= 12;
                year++;
            }
            System.out.println(String.format("%d %d %d, %d %d %d",todayYear, todayMonth, todayDate, year, month, date));
            if(todayYear > year) {
                arrList.add(i + 1);
            } else if(todayYear == year) {
                if(todayMonth > month) {
                    arrList.add(i + 1);
                } else if(todayMonth == month) {
                    if(todayDate > date) {
                        arrList.add(i + 1);
                    }
                }
            }
        }
        int[] answer = arrList.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}