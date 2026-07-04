class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        mp = { 0 : 1}
        curSum = 0

        for n in nums:
            curSum += n
            diff = curSum - k
            res += mp.get(diff, 0)
            mp[curSum] = 1 + mp.get(curSum, 0)
        
        return res