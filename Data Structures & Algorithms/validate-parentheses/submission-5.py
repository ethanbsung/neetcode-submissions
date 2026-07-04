class Solution:
    def isValid(self, s: str) -> bool:
        parens = { ')' : '(', '}' : '{', ']' : '['}
        stack = []

        for i in range(len(s)):
            if s[i] in parens:
                if not stack or parens[s[i]] != stack[-1]:
                    return False
                else:
                    stack.pop()
            else:
                stack.append(s[i])
        
        if not stack:
            return True
        else:
            return False