class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 3:
            return [nums] if sum(nums) == 0 else []
        
        answer = []

        nums_sort = sorted(list(set(nums)))
        nums_count = collections.Counter(nums)

        for i in range(len(nums_sort)):
            num1 = nums_sort[i]
            nums_count[num1] -= 1
            for j in range(i, len(nums_sort)):
                num2 = nums_sort[j]     
                if nums_count[num2]:
                    
                    nums_count[num2] -= 1
                    sums = num1 + num2

                    if num1 == 0 and num2 == 0:
                        if nums_count[0]:
                            answer.append([0,0,0])
                            break
                    if sums >= 0:
                        nums_count[num2] += 1
                        break
                    if nums_count[(-1) * sums] and (-1) * sums >= num2:
                        answer.append([num1, num2, (-1) * sums])
                    nums_count[num2] += 1
            nums_count[num1] += 1
        
        return answer
      
