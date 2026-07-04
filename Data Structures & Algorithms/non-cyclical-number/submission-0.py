class Solution:
    def isHappy(self, n: int) -> bool:
        digits = [int(d) for d in str(n)]
        sum = 0
        numSet = set()

        for n in digits:
            sum += pow(n, 2)

        if sum == 1:
            return True
        
        numSet.add(sum)

        while sum != 1:
            digits = [int(d) for d in str(sum)]
            sum = 0   
            for num in digits:
                sum += pow(num, 2)
                num = pow(num, 2)
            
            if sum == 1:
                return True

            if sum in numSet:
                return False
            
            numSet.add(sum)
        