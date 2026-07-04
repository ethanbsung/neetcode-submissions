class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        list = []
        for i in nums:
            if i in list:
                return True
            list.append(i)
        return False