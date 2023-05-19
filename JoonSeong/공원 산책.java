import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] park, String[] routes) {
        int width = park[0].length();
        int height = park.length;
        String[][] arr = new String[height][width];
        int currRow = -1, currCol = -1;
        for(int i = 0; i < height; i++) {
            String[] row = park[i].split("");
            for(int j = 0; j < row.length; j++) {
                arr[i][j] = row[j];
                if(arr[i][j].equals("S")) {
                    currRow = i;
                    currCol = j;
                }
            }
        }
        for(int i = 0; i < routes.length; i++) {
            String direction = routes[i].split(" ")[0];
            int amount = Integer.parseInt(routes[i].split(" ")[1]);
            Boolean flag = true;
            if(direction.equals("N")) {
                if(currRow - amount < 0) {
                    flag = false;
                } else {
                    for(int j = 1; j <= amount; j++) {
                        if(arr[currRow - j][currCol].equals("X")) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) {
                    currRow -= amount;
                }
            } else if(direction.equals("S")) {
                if(currRow + amount > height - 1) {
                    flag = false;
                } else {
                    for(int j = 1; j <= amount; j++) {
                        if(arr[currRow + j][currCol].equals("X")) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) {
                    currRow += amount;
                }
            } else if(direction.equals("W")) {
                if(currCol - amount < 0) {
                    flag = false;
                } else {
                    for(int j = 1; j <= amount; j++) {
                        if(arr[currRow][currCol - j].equals("X")) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) {
                    currCol -= amount;
                }
            } else {
                if(currCol + amount > width - 1) {
                    flag = false;
                } else {
                    for(int j = 1; j <= amount; j++) {
                        if(arr[currRow][currCol + j].equals("X")) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) {
                    currCol += amount;
                }
            }
        }
        int[] answer = {currRow, currCol};
        return answer;
    }
}