class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)
        stack = []

        for i, t in enumerate(temperatures):
            while stack and stack[-1][1] < t:
                tmp, idx = stack[-1][1], stack[-1][0]
                res[idx] = i - idx
                stack.pop()

            stack.append((i, t))
        
        return res