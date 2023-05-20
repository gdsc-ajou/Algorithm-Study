class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = []
        cur = 1
        for i in range(len(nums)):
            answer.append(cur)
            cur *= nums[i]
        
        cur = nums[-1]
        for i in reversed(range(len(nums) - 1)):
            answer[i] = answer[i] * cur
            cur *= nums[i]

        return answer
        
