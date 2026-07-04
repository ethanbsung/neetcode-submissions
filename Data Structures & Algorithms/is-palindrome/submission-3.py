class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            if not self.isChar(s[l]) and not self.isChar(s[r]):
                l += 1
                r -= 1
                continue
            elif not self.isChar(s[l]) and self.isChar(s[r]):
                l += 1
                continue
            elif self.isChar(s[l]) and not self.isChar(s[r]):
                r -= 1
                continue
            else:
                if s[l].lower() != s[r].lower():
                    return False
                l += 1
                r -= 1
            
        return True

    def isChar(self, c):
        if 'a' <= c <= 'z' or 'A' <= c <= 'Z' or '0' <= c <= '9':
            return True
        return False

"""
    Two pointer problem
    compare the two pointers on each end of the string
    return false if they are different

"""