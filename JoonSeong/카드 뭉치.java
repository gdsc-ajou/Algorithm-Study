class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        int idx1 = 0, idx2 = 0;
        boolean flag = true;
        for(int i = 0; i < goal.length; i++) {
            if(cards1[idx1].equals(goal[i])) {
                if(idx1 + 1 < cards1.length) idx1++;
            } else if(cards2[idx2].equals(goal[i])) {
                if(idx2 + 1 < cards2.length) idx2++;
            } else {
                flag = false;
                break;
            }
        }
        if(flag) {
            return "Yes";
        } else {
            return "No";
        }
    }
}