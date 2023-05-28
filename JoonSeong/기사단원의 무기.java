class Solution {
    public int solution(int number, int limit, int power) {
        int[] arr = new int[number + 1];
        for(int i = 1; i <= number; i++) {
            int k = i;
            while(k <= number) {
                arr[k]++;
                k += i;
            }
        }
        int answer = 0;
        for(int i = 1; i <= number; i++) {
            if(arr[i] > limit) arr[i] = power;
            answer += arr[i];
        }
        return answer;
    }
}