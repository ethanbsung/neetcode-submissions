class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # time = (target - position) / speed
        
        pair = [[p, s] for p, s in zip(position, speed)]
        pair.sort(reverse=True)
        stack = []

        for p, s in pair:
            t = (target - p) / s
            if not stack:
                stack.append(t)
            elif stack and t > stack[-1]:
                stack.append(t)
        
        return len(stack)