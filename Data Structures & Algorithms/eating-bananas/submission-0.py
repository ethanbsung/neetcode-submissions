class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 0, max(piles)
        res = 0

        while l <= r:
            k = (l + r) // 2
            if k > 0:
                sum = 0
                for p in piles:
                    sum += math.ceil(p / k)
                if sum <= h:
                    res = k
                    r = k - 1
                else:
                    l = k + 1
            else:
                break
        
        return res