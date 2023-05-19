class Solution {
    public int[] solution(String[] wallpaper) {
        int width = wallpaper[0].length();
        int height = wallpaper.length;
        int left = 2147483647, right = -1, top = 2147483647, bottom = -1;
        for(int i = 0; i < height; i++) {
            String[] row = wallpaper[i].split("");
            for(int j = 0; j < width; j++) {
                if(row[j].equals("#")) {
                    if(i + 1 > bottom) bottom = i + 1;
                    if(i < top) top = i;
                    if(j + 1 > right) right = j + 1;
                    if(j < left) left = j;
                }
            }
        }
        int[] answer = {top, left, bottom, right};
        return answer;
    }
}