class Solution:
    def isValid(self, s: str) -> bool:
        map = {'}' : '{', ')' : '(', ']' : '['}
        stack = []

        for c in s:
            if stack:
                if c in map:
                    if stack[-1] == map[c]:
                        stack.pop()
                        continue
                    else:
                        return False
                else:
                    stack.append(c)
                
            else:
                stack.append(c)
        return not stack
            