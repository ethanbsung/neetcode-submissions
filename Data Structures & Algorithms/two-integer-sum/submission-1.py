class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i in range(len(nums)):
            t = target - nums[i]
            if t in seen:
                return [seen[t], i]
            seen[nums[i]] = i