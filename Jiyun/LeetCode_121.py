class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        answer = 0
        buy = prices[0]

        for price in prices:
            buy = min(price, buy)
            answer = max(answer, price - buy)
        
        return answer
      
