class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []

        for i, n in enumerate(nums):
            if n > 0:
                break;

            if i > 0 and n == nums[i - 1]:
                continue

            j, k = i + 1, len(nums) - 1

            while j < k:
                threeSum = n + nums[j] + nums[k]
                
                if threeSum > 0:
                    k -= 1
                elif threeSum < 0:
                    j += 1
                else:
                    res.append([n, nums[j], nums[k]])
                    k -= 1
                    j += 1
                    while nums[j - 1] == nums[j] and j < k:
                        j += 1
        
        return res